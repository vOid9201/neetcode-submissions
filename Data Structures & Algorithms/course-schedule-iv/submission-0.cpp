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
        // vector<int> indegree(n,0);
        // vector<int> levels(n,0);
        vector<bool> vis(n,false);
        vector<bool> ans;
        // queue<pair<int,int>> qt;

        for(auto x : prerequisites){
            adj[x[0]].push_back(x[1]);
            // indegree[x[1]] ++;
        }

        // for(int i=0;i<n;i++){
        //     if(indegree[i] == 0) qt.push({i,0});
        // }

        // while(!qt.empty()){
        //     int curr_node = qt.front().first , level = qt.front().second;
        //     qt.pop();
        //     levels[curr_node] = level;
        //     for(auto x : adj[curr_node]){
        //         indegree[x] -- ;
        //         if(indegree[x] == 0) qt.push({x,level+1});
        //     }
        // }
        
        for(auto x : queries){
            for(int i=0;i<n;i++) vis[i] = false;
            dfs(x[0],adj,vis);
            ans.push_back(vis[x[1]]);
        }

        return ans;

    }
};