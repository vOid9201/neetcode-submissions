class Solution {
public:

    vector<vector<int>> movt = {{0,-1},{0,1},{-1,0},{1,0}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size() , m = heights[0].size();
        vector<vector<int>> pacific(n,vector<int>(m,-1));
        vector<vector<int>> atlantic(n,vector<int>(m,-1));
        
        queue<pair<int,int>> qtPacific;
        queue<pair<int,int>> qtAtlantic;
        
        for(int j=0;j<m;j++) qtPacific.push({-1,j}) , qtAtlantic.push({n,j});
        for(int i=0;i<n;i++) qtPacific.push({i,-1}) , qtAtlantic.push({i,m});
        
        while(!qtPacific.empty()){
            int curr_i = qtPacific.front().first , curr_j = qtPacific.front().second;
            qtPacific.pop();
            
            for(auto x : movt){
                int n_i = curr_i + x[0] , n_j = curr_j + x[1];
                if(n_i >=0 and n_i < n and n_j >= 0 and n_j < m){
                    if(pacific[n_i][n_j] == -1){
                        if( (curr_i == -1 || curr_j == -1) || 
                        (heights[n_i][n_j] >= heights[curr_i][curr_j])){
                            pacific[n_i][n_j] = 1;
                            qtPacific.push({n_i,n_j});
                        }
                    }
                }
            }
        }
        
        while(!qtAtlantic.empty()){
            int curr_i = qtAtlantic.front().first , curr_j = qtAtlantic.front().second;
            qtAtlantic.pop();
            
            for(auto x : movt){
                int n_i = curr_i + x[0] , n_j = curr_j + x[1];
                if(n_i >=0 and n_i < n and n_j >= 0 and n_j < m){
                    if(atlantic[n_i][n_j] == -1){
                        if( (curr_i == n || curr_j == m) || 
                        (heights[n_i][n_j] >= heights[curr_i][curr_j])){
                            atlantic[n_i][n_j] = 1;
                            qtAtlantic.push({n_i,n_j});
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] == 1 and atlantic[i][j] == 1)
                    ans.push_back({i,j});
            }
        }
        
        
        return ans;
    }
};
