class Solution {
public:

    vector<int> cycle;

    void dfs(int currNode,int parNode,vector<int> &par,vector<int> adj[]){
        par[currNode] = parNode;
        for(auto x : adj[currNode]){
            if(par[x] != -1 and x != parNode){
                if(cycle.empty()) {
                    cycle.push_back(currNode);
                    cycle.push_back(x);
                }
            }

            else if(par[x] == -1) dfs(x,currNode,par,adj);
        }
        return;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        const int x = n;
        vector<int> adj[101];
        vector<int> par(101,-1);
        cycle.clear();

        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        dfs(1,0,par,adj);
        set<int> st;
        st.insert(cycle[1]);
        
        
        int node = cycle[0];
        while(node != cycle[1]){
            st.insert(node);
            node = par[node];
        }

        for(int i=n-1;i>=0;i--){
            if(st.find(edges[i][0]) != st.end() and st.find(edges[i][1]) != st.end())
                return edges[i];
        }
        return {};
    }
};
