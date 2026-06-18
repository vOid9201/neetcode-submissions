class Solution {
public:

    int dfsForSubtree(int curr, int par,vector<int> adj[],vector<vector<int>> &dp){
        //for calculating subtree data 
        int maximum = INT_MIN , second_maximum = INT_MIN;
        for(auto x : adj[curr]){
            if(x == par) continue;
            else{
                int subTreeHeight = 1+dfsForSubtree(x,curr,adj,dp);
                if(maximum < subTreeHeight){
                    second_maximum = maximum ;
                    maximum = subTreeHeight;
                }else if(maximum == subTreeHeight || second_maximum < subTreeHeight) {
                    second_maximum = subTreeHeight;
                }
            }
        }

        dp[curr][0] = max(maximum , 0) , dp[curr][1] = max(second_maximum,0);
        return dp[curr][0];
    }

    int updateParentSubtree(int curr,int par,vector<int> adj[],vector<vector<int>> &dp){
        //updates from parents other subchildren
        if(par >= 0){
            int parHeight = (1+dp[curr][0] == dp[par][0]) ? 1+max(dp[par][1],0) : 1+dp[par][0];
            if(dp[curr][0] < parHeight){
                dp[curr][1] = dp[curr][0];
                dp[curr][0] = parHeight;
            }else if(dp[curr][0] == parHeight || dp[curr][1] < parHeight){
                dp[curr][1] = parHeight;
            }
        }

        int minHeightTree = INT_MAX;

        for(auto x : adj[curr]){
            if(x == par) continue;
            else minHeightTree = min(updateParentSubtree(x,curr,adj,dp),minHeightTree);
        }
        //this is the diameter of a tree 
        // dp[curr][0] += dp[curr][1];

        //return minimum height of the tree 
        return min(minHeightTree,dp[curr][0]);
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> adj[20001];
        vector<vector<int>> dp(20001,vector<int>(2,0));

        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        dfsForSubtree(0,-1,adj,dp);
        int minHeight = updateParentSubtree(0,-1,adj,dp);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(dp[i][0] == minHeight) ans.push_back(i);
        }
        return ans;
    }
};