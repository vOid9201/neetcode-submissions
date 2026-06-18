class Solution {
public:

    void dfs(int node,vector<int> adj[],vector<bool> &vis){
        vis[node] = true;
        for(auto x : adj[node]){
            if(!vis[x]) dfs(x,adj,vis);
        }
        return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        // int size = n;
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
                dfs(i,adj,vis);
            }
        }

        return countOfComponents;
    }
};
