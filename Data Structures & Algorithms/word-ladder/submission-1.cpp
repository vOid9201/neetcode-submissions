class Solution {
public:
    int countDiff(string &beginWord, string &endWord){
	int countDiff = 0;
	for(int i=0;i<beginWord.size();i++){
		if(beginWord[i] != endWord[i]) countDiff ++;
	}
	
	return countDiff ;
}

int ladderLength(string beginWord,string endWord,vector<string>& wordList){
	int n = (int) wordList.size();
	vector<int> adj[n];
	vector<bool> vis(n,false);
	queue<pair<int,int>> qt;
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(countDiff(wordList[i],wordList[j]) == 1){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
		
		if(countDiff(beginWord,wordList[i]) == 1){
			vis[i] = true;
			qt.push({i,1});
		}
	}
	
	while(!qt.empty()){
		int currIndex = qt.front().first , level = qt.front().second;
		qt.pop();
		if(wordList[currIndex] == endWord) return level+1;
		for(auto x : adj[currIndex]){
			if(!vis[x]){
				vis[x] = true;
				qt.push({x,level+1});
			}
		}
	}
	
	return 0;

}
};
