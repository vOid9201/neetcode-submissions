class Solution {
public:

    vector<vector<int>> movt = {{0,-1},{-1,0}};

    int solve(int i,int j,vector<vector<int>>&obstacleGrid,int n,int m,
    vector<vector<int>> &dp){
        if(i == 0 && j == 0) return dp[i][j] = (obstacleGrid[i][j] + 1)%2;
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 0;
        for(auto x : movt){
            int n_i = i+x[0] , n_j = j+x[1];
            if(n_i >= 0 and n_i < n and n_j >= 0 and n_j < m and obstacleGrid[n_i][n_j] == 0){
                dp[i][j] += solve(n_i,n_j,obstacleGrid,n,m,dp);
            }
        }
        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size() , m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
            }
        }

        return solve(n-1,m-1,obstacleGrid,n,m,dp);
    }
};