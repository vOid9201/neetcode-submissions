class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        	set<string> visited;
	queue<pair<string,int>> qt;
	
	for(auto x : deadends) visited.insert(x);
    if(visited.find("0000") != visited.end())  return -1;
	qt.push({"0000",0});
	visited.insert("0000");
	
	while(!qt.empty()){
		string curr = qt.front().first;
		int level = qt.front().second;
		qt.pop();
		if(curr == target) return level;
		
		for(int i=0;i<4;i++){
			
			char incrCh = (char)('0' + ((curr[i]-'0') + 1)%10);
			char decrCh = (char)('0' + (10 + (curr[i]-'0') - 1)%10);
			
			string incr = curr , decr = curr;
			incr[i] = incrCh , decr[i] = decrCh;
			
			if(visited.find(incr) == visited.end()) {
				qt.push({incr,level+1});
				visited.insert(incr);
			}
			
			if(visited.find(decr) == visited.end() ){
				qt.push({decr,level+1});
				visited.insert(decr);
			}
		
		}
	}
	
	return -1;
    }
};