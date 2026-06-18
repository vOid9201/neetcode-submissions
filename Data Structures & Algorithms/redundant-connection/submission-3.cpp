class Solution {
public:

    // vector<int> cycle;

    // void dfs(int currNode,int parNode,vector<int> &par,vector<int> adj[]){
    //     par[currNode] = parNode;
    //     for(auto x : adj[currNode]){
    //         if(par[x] != -1 and x != parNode){
    //             if(cycle.empty()) {
    //                 cycle.push_back(currNode);
    //                 cycle.push_back(x);
    //             }
    //         }

    //         else if(par[x] == -1) dfs(x,currNode,par,adj);
    //     }
    //     return;
    // }

    // vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    //     // int n = edges.size();
    //     // const int x = n;
    //     // vector<int> adj[101];
    //     // vector<int> par(101,-1);
    //     // cycle.clear();

    //     // for(auto x : edges){
    //     //     adj[x[0]].push_back(x[1]);
    //     //     adj[x[1]].push_back(x[0]);
    //     // }

    //     // dfs(1,0,par,adj);
    //     // set<int> st;
    //     // st.insert(cycle[1]);
        
        
    //     // int node = cycle[0];
    //     // while(node != cycle[1]){
    //     //     st.insert(node);
    //     //     node = par[node];
    //     // }

    //     // for(int i=n-1;i>=0;i--){
    //     //     if(st.find(edges[i][0]) != st.end() and st.find(edges[i][1]) != st.end())
    //     //         return edges[i];
    //     // }
    //     // return {};

    //     	int n = edges.size();
	// vector<int> adj[101];
	// vector<int> vis(101,false);
	// vector<int> indegree(101,0);
	// queue<int> qt;
	
	// for(auto x : edges){
	// 	adj[x[0]].push_back(x[1]);
	// 	adj[x[1]].push_back(x[0]);
	// 	indegree[x[0]]++;
	// 	indegree[x[1]]++;
	// }
	
	// for(int i=1;i<=n;i++){
	// 	if(indegree[i] == 1){
	// 		qt.push(i);
	// 		vis[i] = true;
	// 	}
	// }
	
	// while(!qt.empty()){
	// 	int curr = qt.front();
	// 	qt.pop();
		
	// 	for(auto x : adj[curr]){
	// 		if(!vis[x]){
	// 			indegree[x] -- ;
	// 			if(indegree[x] == 1){
	// 				qt.push(x);
	// 				vis[x] = true;
	// 			}
	// 		}
	// 	}
	// }
	
	// for(int i=n-1;i>=0;i--){
	// 	if(!vis[edges[i][0]] and !vis[edges[i][1]]) return edges[i];
	// }
	
	// return {};
    // }

    int cycleEnd = -1 , cycleStart = -1 ;
set<int> cycle;

void dfs(int currNode,int parNode,vector<int> adj[],vector<bool> &visited){
	visited[currNode] = true;
	for(auto x: adj[currNode]){
		if(visited[x] and x != parNode){
			cycleEnd = currNode;
			cycleStart = x;
			cycle.insert(currNode);
			return;
		}
		
		else if(!visited[x]) {
			dfs(x,currNode,adj,visited);
			if(cycleEnd != -1){
				cycle.insert(currNode);
				if(currNode == cycleStart) cycleEnd = -1;
				return;
			}
		}
	}
	
	return;
}

vector<int> findRedundantConnection(vector<vector<int>> &edges){
	int n = edges.size();
	vector<int> adj[101];
	vector<bool> visited(101,false);
    
    for(auto x : edges){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }

	dfs(1,0,adj,visited);
	
	for(int i=n-1;i>=0;i--){
		if(cycle.find(edges[i][0]) != cycle.end() and cycle.find(edges[i][1]) != cycle.end())
			return edges[i];
	}
	
	return {};
}
};
