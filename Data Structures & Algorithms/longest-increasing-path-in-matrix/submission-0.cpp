class Solution {
public:
    vector<pair<int,int>> movt = {{-1,0},{0,-1},{1,0},{0,1}};
    int solve(int i,int j,int n,int m,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for(auto x : movt){
            int new_i = i+x.first , new_j = j+x.second;
            if((new_i >= 0 and new_i<n) and (new_j>=0 and new_j<m) and (matrix[new_i][new_j] > matrix[i][j]))
                ans = max(ans , solve(new_i,new_j,n,m,matrix,dp));
        }

        return dp[i][j] = 1+ans;    
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans , solve(i,j,n,m,matrix,dp));
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++) cout << dp[i][j] << " ";
        //     cout << '\n';
        // }
        return ans;
    }
};
