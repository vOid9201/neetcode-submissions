class Solution {
public:

    void dfs(int curr,vector<int> adj[],vector<bool> &vis){
        vis[curr] = true;
        for(auto x : adj[curr]){
            if(!vis[x]) dfs(x,adj,vis);
        }
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    
	vector<int> adj[n];
	vector<int> indegree(n,0);
	unordered_map<int,set<int>> successors;
	vector<bool> ans;
	queue<int> qt;
	
	for(int i=0;i<n;i++){
		successors[i].insert(i);
	}
	
	for(auto x : prerequisites){
		adj[x[0]].push_back(x[1]);
		indegree[x[1]] ++;
	}
	
	for(int i=0;i<n;i++){
		if(indegree[i] == 0){
			qt.push(i);
		}
	}
	
	while(!qt.empty()){
		int curr = qt.front();
		qt.pop();
		for(auto x : adj[curr]){
			successors[x].insert(successors[curr].begin(),successors[curr].end());
			indegree[x] --;
			if(indegree[x] == 0) qt.push(x);
		}
	}
	
	for(auto x : queries){
		if(successors[x[1]].find(x[0]) != successors[x[1]].end()) 
			ans.push_back(true);
		else ans.push_back(false);
	}
	
	return ans;

    }
};