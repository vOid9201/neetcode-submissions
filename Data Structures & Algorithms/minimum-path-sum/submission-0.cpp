class Solution {
public:

    vector<vector<int>> movt = {{0,-1},{-1,0}};

    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp,int n,int m){
        if(i == 0 && j == 0) return dp[i][j] = grid[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];
        for(auto x : movt){
            int n_i = i+x[0] , n_j = j+x[1];
            if(n_i >= 0 and n_i < n and n_j >= 0 and n_j < m){
                dp[i][j] = min(dp[i][j] , solve(n_i,n_j,grid,dp,n,m));
            }
        }
        return dp[i][j] += grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        return solve(n-1,m-1,grid,dp,n,m);
    }
};