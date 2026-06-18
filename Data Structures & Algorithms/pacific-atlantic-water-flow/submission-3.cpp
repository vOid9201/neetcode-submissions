class Solution {
public:

    vector<vector<int>> movt = {{0,-1},{0,1},{-1,0},{1,0}};

int traverseComponent(vector<vector<int>> &heights,vector<vector<int>> &flow,
vector<vector<bool>> &vis,int i,int j,int n,int m){
	
	vis[i][j] = true;
	bool pacific = false , atlantic = false;
	for(auto x : movt){
		int childrens_ans = -1;
		int n_i = i+x[0] , n_j = j+x[1];
		if(n_i == -1 || n_j == -1) pacific = true;
		if(n_i == n || n_j == m) atlantic = true;
		
		else{
			if(n_i >= 0 and n_i < n and n_j >= 0 and n_j < m
			and heights[n_i][n_j] <= heights[i][j]){
				if(!vis[n_i][n_j])
					childrens_ans = traverseComponent(heights,flow,vis,n_i,n_j,n,m);
				else 
					childrens_ans = flow[n_i][n_j];
			}
			
			if(childrens_ans == 0) pacific = true;
			else if(childrens_ans == 1) atlantic = true;
			else if(childrens_ans == 2) pacific = true, atlantic = true; 
		}
	}
	
	return flow[i][j] = pacific && atlantic ? 2 :
						(pacific ? 0 : (atlantic ? 1 : -1));

}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights){
	
	int n = heights.size() , m = heights[0].size();
	vector<vector<int>> flow(n,vector<int>(m,-1));
	vector<vector<bool>> vis(n,vector<bool>(m,false));
	
	vector<vector<int>> ans;	
		
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			flow[i][j] = traverseComponent(heights,flow,vis,i,j,n,m);
			if(flow[i][j] == 2) ans.push_back({i,j});
		}
	}

	return ans;

}
};
