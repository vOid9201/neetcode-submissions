class Solution {
public:

    vector<vector<int>> movt = {{0,1},{0,-1},{-1,0},{1,0}};

    int calculatePerimeter(vector<vector<bool>>&vis,vector<vector<int>>&grid,int i,int j,int n,int m){
        vis[i][j] = true;
        int edges = 4;
        int childsPerimeter = 0;
        for(auto x : movt){
            int next_i = i+x[0] , next_j = j+x[1];
            if(next_i >=0 and next_i < n and next_j >=0 and next_j < m 
            and grid[next_i][next_j] == 1){
                edges --;
                if(!vis[next_i][next_j]){
                    childsPerimeter += calculatePerimeter(vis,grid,next_i,next_j,n,m);
                }
            }
        }

        return edges+childsPerimeter;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 and !vis[i][j]){
                    ans += calculatePerimeter(vis,grid,i,j,n,m);
                }
            }
        }

        return ans;
    }
};