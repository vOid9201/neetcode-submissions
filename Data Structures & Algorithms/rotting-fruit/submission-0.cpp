class Solution {
public:

    vector<vector<int>> movt = {{0,-1},{0,1},{-1,0},{1,0}};

    void rottenOranges(vector<vector<int>>&grid, vector<vector<int>>&distances,
    int i,int j,int n,int m){

        for(auto x : movt){
            int n_i = i+x[0] , n_j = j+x[1];
            if(n_i >= 0 and n_i < n and n_j >= 0 and n_j < m and 
            grid[n_i][n_j] == 1){

                if(distances[n_i][n_j] > 1+distances[i][j]){
                    distances[n_i][n_j] = 1+distances[i][j];
                    rottenOranges(grid,distances,n_i,n_j,n,m);
                }
            }
        }

        return;

    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> distances(n,vector<int>(m,INT_MAX));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0) distances[i][j] = -1;
                else if(grid[i][j] == 2){
                    distances[i][j] = 0;
                    rottenOranges(grid,distances,i,j,n,m);
                }
            }
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,distances[i][j]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }

};
