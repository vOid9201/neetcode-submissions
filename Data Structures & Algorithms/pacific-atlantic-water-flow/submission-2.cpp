class Solution {
public:

    vector<vector<int>> movt = {{0,-1},{0,1},{-1,0},{1,0}};

    int traverseConnectedComponenet(vector<vector<int>> &heights,vector<vector<int>> &flow,
    vector<vector<bool>> &vis , int i,int j,int n,int m,int par_i,int par_j){

        vis[i][j] = true;

        bool pacific = false, atlantic = false;    
        int int_ans = -1;
        for(auto x : movt){
            int n_i = i+x[0] , n_j = j+x[1];
            if(n_i == par_i and n_j == par_j)  continue;
            if(n_j == -1 || n_i == -1) pacific = true;
            if(n_i == n || n_j == m) atlantic = true;

            else if(n_i >= 0 and n_i < n and n_j >= 0 and n_j < m and heights[n_i][n_j] <= heights[i][j]){
                if(!vis[n_i][n_j]){
                    int_ans = traverseConnectedComponenet(heights,flow,vis,n_i,n_j,n,m,i,j);
                }else{
                    int_ans = flow[n_i][n_j];
                }
            }

            if(int_ans == 0) pacific = true;
            if(int_ans == 1) atlantic = true;
            if(int_ans == 2 ) pacific = true , atlantic = true;
        }

        return flow[i][j] = (pacific && atlantic) ? 2 : ((pacific) ? 0 : ((atlantic) ? 1 : -1));  

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size() , m = heights[0].size();
        vector<vector<int>> flowTowards(n,vector<int>(m,-1));
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    flowTowards[i][j] = traverseConnectedComponenet(heights,flowTowards,vis,i,j,n,m,-2,-2);
                    // if(flowTowards[i][j] == 2) ans.push_back({i,j});
                // }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(flowTowards[i][j] == 2) ans.push_back({i,j});
            }
        }

        return ans;

    }
};
