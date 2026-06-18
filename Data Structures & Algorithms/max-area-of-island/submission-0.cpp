class Solution {
public:
    vector<vector<int>> movt = {{0,-1},{0,1},{-1,0},{1,0}};

    int areaOfIsland(vector<vector<int>>&grid,vector<vector<bool>>&vis,
    int i,int j,int n,int m){
        vis[i][j] = true;
        int overallContribution = 1;
        for(auto x : movt){
            int n_i = i+x[0] , n_j = j+x[1];
            if(n_i >= 0 and n_i < n and n_j >= 0 and n_j < m
            and grid[n_i][n_j] == 1 and !vis[n_i][n_j]){
                overallContribution += areaOfIsland(grid,vis,n_i,n_j,n,m);
            }
        }
        return overallContribution;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        int maxAreaOfIsland = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 and !vis[i][j]){
                    maxAreaOfIsland = max(maxAreaOfIsland , areaOfIsland(grid,vis,i,j,n,m));
                }
            }
        }

        return maxAreaOfIsland;
    }
};
