class Solution {
public:

    vector<vector<int>> movt = {{-1,0},{0,-1}};

    int solve(int i,int j,vector<vector<int>> &dp,int n, int m){
        if(i == 0 and j == 0) return dp[0][0] = 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 0;
        for(auto x : movt){
            int n_i = i+x[0] , n_j = j+x[1];
            if(n_i >= 0 and n_i < n and n_j >= 0 and n_j < m)
                dp[i][j] += solve(n_i,n_j,dp,n,m);
        }

        return dp[i][j];

    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp,m,n);
    }
};
