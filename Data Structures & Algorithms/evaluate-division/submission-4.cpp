class Solution {
public:

    void dfs(unordered_map<string,unordered_map<string,double>> &adj,
    unordered_map<string,unordered_map<string,double>> &vis, 
    unordered_map<string,string> &parent,
    string curr,string par,string actPar){
        vis[curr][curr] = 1.0;
        parent[curr] = actPar;
        cout << curr << " " << par << '\n';
        for(auto x : adj[curr]){
            if(x.first != par){
                if(vis.find(x.first) == vis.end()) dfs(adj,vis,parent,x.first,curr,actPar);
                for(auto y : vis[x.first]){
                    vis[curr][y.first] = x.second*y.second;
                }
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> adj;
        unordered_map<string,unordered_map<string,double>> vis;
        unordered_map<string,string> parent;
        for(int i=0;i<equations.size();i++){
            adj[equations[i][0]][equations[i][1]] = values[i];
            adj[equations[i][1]][equations[i][0]] = 1/values[i];
        }

        for(auto x : adj){
            cout << x.first << '\n';
            for(auto y : x.second) cout << y.first << " " << y.second << " , ";
            cout << '\n';
        }

        for(auto x : adj){
            if(vis.find(x.first) == vis.end()){
                dfs(adj,vis,parent,x.first,"",x.first);
            }
        }

        vector<double> ans;

        for(auto x : queries){
            if(vis.find(x[0]) == vis.end() || vis.find(x[1])  == vis.end() || 
            (parent[x[0]] != parent[x[1]])){
                ans.push_back(-1.00);
            }else{
                if(vis[x[0]].find(x[1]) != vis[x[0]].end()) ans.push_back(vis[x[0]][x[1]]);
                else if(vis[x[1]].find(x[0]) != vis[x[1]].end()) ans.push_back(1/vis[x[1]][x[0]]);
                else
                    ans.push_back(vis[parent[x[0]]][x[1]] / vis[parent[x[0]]][x[0]]);
            }
        }

        return ans;
    }
};