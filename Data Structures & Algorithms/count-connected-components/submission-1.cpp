class Solution {
public:

    void bfs(int node,vector<int> adj[],vector<bool>&vis){
	queue<int> qt;
	qt.push(node);
	vis[node] = true;
	
	while(!qt.empty()){
		int curr_node = qt.front();
		qt.pop();
		for(auto x : adj[curr_node]){
			if(!vis[x]){
				vis[x] = true;
				qt.push(x);
			}
		}
	}
	
	return;
}

int countComponents(int n,vector<vector<int>> &edges){
	vector<int> adj[2001];
	vector<bool> vis(2001,false);
	int countOfComponents = 0;
	
	for(auto x : edges){
		adj[x[0]].push_back(x[1]);
		adj[x[1]].push_back(x[0]);
	}
	
	for(int i=0;i<n;i++){
		if(!vis[i]){
			countOfComponents ++ ;
			bfs(i,adj,vis);
		}
	}
	
	return countOfComponents;
	
}
};
