class Solution {
public:

    vector<vector<int>> movt = {{0,-1},{-1,0}};

    int solve(int i,int j,int n,int m,
    vector<vector<int>> &dp){
        if(i == 0 && j == 0) return dp[i][j] = (dp[i][j] == -1) ? 1 : dp[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 0;
        for(auto x : movt){
            int n_i = i+x[0] , n_j = j+x[1];
            if(n_i >= 0 and n_i < n and n_j >= 0 and n_j < m){
                dp[i][j] += solve(n_i,n_j,n,m,dp);
            }
        }
        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // int n = obstacleGrid.size() , m = obstacleGrid[0].size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
        //     }
        // }

        // return solve(n-1,m-1,n,m,dp);
        	int n = obstacleGrid.size() , m = obstacleGrid[0].size();
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
		
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(obstacleGrid[i-1][j-1] == 1) continue;
			else{
				if(i == 1 and j == 1) dp[i][j] = 1;
				else dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
	}
	
	return dp[n][m];
    }
};