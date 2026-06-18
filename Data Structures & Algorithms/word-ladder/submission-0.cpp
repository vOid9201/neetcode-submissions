class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = (int) wordList.size();
        vector<int> adj[101];
        queue<pair<int,int>> qt;
        vector<bool> vis(n+1,false);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int countDiff = 0;
                for(int k=0;k<wordList[i].size();k++){
                    if(wordList[i][k] != wordList[j][k])
                        countDiff ++ ;
                }
                if(countDiff == 1)
                    adj[i+1].push_back(j+1),adj[j+1].push_back(i+1);
            }
        }

        for(int i=0;i<n;i++){
            int countDiff = 0;
            for(int j=0;j<beginWord.size();j++){
                if(beginWord[j] != wordList[i][j]) countDiff ++;
            }
            if(countDiff == 1)
                qt.push({i+1,1}) , vis[i+1] = true;
        }

        while(!qt.empty()){
            int currIndex = qt.front().first , level = qt.front().second;
            qt.pop();
            if(wordList[currIndex-1] == endWord) return level+1;
            for(auto x : adj[currIndex]){
                if(!vis[x]) {
                    vis[x] = true;
                    qt.push({x,level+1});
                }
            }
        }

        return 0;

    }
};
