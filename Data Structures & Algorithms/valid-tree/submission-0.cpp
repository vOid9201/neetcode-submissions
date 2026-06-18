class Solution {
public:
    int count = 0;

    bool dfs(int curr_node, int par_node,vector<int> adj[],vector<bool> &vis){
        vis[curr_node] = true;
        bool ans = true;
        count ++ ;
        for(auto x : adj[curr_node]){
            if(x != par_node ){
                if(vis[x]) return false;
                ans &= dfs(x,curr_node,adj,vis);
            }
        }
        return ans;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<int> adj[n];
        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        return dfs(0,-1,adj,vis) && count == n;
    }
};
