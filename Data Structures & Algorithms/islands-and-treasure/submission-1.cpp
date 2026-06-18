class Solution {
public:

    vector<vector<int>> movt = {{0,-1},{0,1},{1,0},{-1,0}};

    void updateDistances(vector<vector<int>>&grid,int i,int j,int n,int m){
        for(auto x : movt){
            int n_i = i+x[0] , n_j = j+x[1];
            if(n_i >=0 and n_i < n and n_j >= 0 and n_j < m and grid[n_i][n_j] > 0){
                if(grid[n_i][n_j] > grid[i][j] + 1){
                    grid[n_i][n_j] = 1+grid[i][j];
                    updateDistances(grid,n_i,n_j,n,m);
                }
            }
        }
        return;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
	queue<pair<int,int>> qt;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j] == 0) qt.push({i,j});
		}
	}
	
	while(!qt.empty()){
		int curr_i = qt.front().first , curr_j = qt.front().second;
		qt.pop();
		
		for(auto x : movt){
			int n_i = curr_i + x[0] , n_j = curr_j + x[1];
			if(n_i >= 0 and n_i < n and n_j >= 0 and n_j < m
			and grid[n_i][n_j] > 0 ){
				
				if(grid[n_i][n_j] > 1+grid[curr_i][curr_j]){
					grid[n_i][n_j] = 1+grid[curr_i][curr_j];
					qt.push({n_i,n_j});
				}
			}
		}
	}
    }
};
