class Solution {
public:

    // void dfs(int node,vector<vector<bool>>& adj,vector<int> &parent,int par){
    //     parent[node] = par;
    //     for(int i=0;i<adj[node].size();i++){
    //         if(adj[node][i] and parent[i] == -1)
    //             dfs(i,adj,parent,par);
    //     }
    //     return;
    // }

    // vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    //    int n = accounts.size();
    //    vector<vector<bool>> adjList(n,vector<bool>(n,false));
    //    vector<int> parent(n,-1);
    //    map<string,int> emailToAccount;

    //    for(int i=0;i<n;i++){
    //         for(int j=1;j<accounts[i].size();j++){
    //             string x = accounts[i][j];
    //             if(emailToAccount.find(x) != emailToAccount.end()){
    //                 adjList[emailToAccount[x]][i] = true;
    //                 adjList[i][emailToAccount[x]] = true;
    //             }else emailToAccount[x] = i;
    //         }
    //    }

    //    for(int i=0;i<n;i++){
    //         if(parent[i] == -1){
    //             dfs(i,adjList,parent,i);
    //         }
    //    }

    //     for(int i=0;i<n;i++) cout << i << " -> " << parent[i] << " ,";
    // //    return {};

    //    map<int,set<string>> answerList;
    //    for(int i=0;i<n;i++){
    //         for(int j=1;j<accounts[i].size();j++) answerList[parent[i]].insert(accounts[i][j]);
    //    }

    //    vector<vector<string>> result;
    //    for(auto x : answerList){
    //         vector<string> temp;
    //         temp.push_back(accounts[x.first][0]);
    //         temp.insert(temp.begin()+1,x.second.begin(),x.second.end());
    //         result.push_back(temp);
    //    }

    //    return result;
    // }
    void dfs(int node,vector<int> adj[],vector<int> &parent,int par){
	parent[node] = par;
	for(auto x : adj[node]){
		if(parent[x] == -1) dfs(x,adj,parent,par);
	}
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
	int n = accounts.size();
	vector<int> adj[n];
	map<string,int> emailToAccount;
	vector<int> parent(n,-1);
	
	for(int i=0;i<n;i++){
		for(int j=1;j<accounts[i].size();j++){
			string email = accounts[i][j];
			if(emailToAccount.find(email) != emailToAccount.end()){
				 adj[emailToAccount[email]].push_back(i);
				 adj[i].push_back(emailToAccount[email]);
			}else emailToAccount[email] = i;
		}
	}
	
	for(int i=0;i<n;i++){
		if(parent[i] == -1)
			dfs(i,adj,parent,i);
	}
	
	map<int,set<string>> mp;
	for(int i=0;i<n;i++){
		for(int j=1;j<accounts[i].size();j++){
			mp[parent[i]].insert(accounts[i][j]);
		}
	}
	
	vector<vector<string>> ans;
	for(auto x : mp){
		vector<string> temp;
		temp.push_back(accounts[x.first][0]);
		temp.insert(temp.begin()+1,x.second.begin(),x.second.end());
		ans.push_back(temp);
	}
	
	return ans;
}
};