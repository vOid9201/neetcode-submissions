class Solution {
public:
    int traversal(string &s,string &t,vector<vector<int>>&dp,int i,int j,vector<vector<int>>&grid){

        if(i == 0 or j == 0) return grid[i][j] = 1;
        if(grid[i][j] != -1) return grid[i][j];
        int ans = 0;
        if(s[i-1] == t[j-1]){
            ans = traversal(s,t,dp,i-1,j-1,grid);
            if(dp[i-1][j] == 1+dp[i-1][j-1]) ans += traversal(s,t,dp,i-1,j,grid);
            if(dp[i][j-1] == 1+dp[i-1][j-1]) ans += traversal(s,t,dp,i-1,j,grid);
        }else{
            if(dp[i-1][j] > dp[i][j-1]) ans += traversal(s,t,dp,i-1,j,grid);
            else if(dp[i-1][j] < dp[i][j-1]) ans += traversal(s,t,dp,i,j-1,grid);
            else ans += traversal(s,t,dp,i,j-1,grid) + traversal(s,t,dp,i-1,j,grid);
        }

        return grid[i][j] = ans;
    }
    int solve(string &s,string &t,int i,int j,vector<vector<int>>&dp){
        if(i == 0 or j == 0) return dp[i][j] = 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == t[j-1])
            dp[i][j] =  max(1+solve(s,t,i-1,j-1,dp), max(solve(s,t,i-1,j,dp) , solve(s,t,i,j-1,dp)));
        else 
            dp[i][j] = max(solve(s,t,i-1,j,dp) , solve(s,t,i,j-1,dp));
    
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        int n = s.size() , m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        vector<vector<int>> grid(n+1,vector<int>(m+1,-1));

        int lcs = solve(s,t,n,m,dp);
        if(lcs != m) return 0;
        return traversal(s,t,dp,n,m,grid);

    }
};

