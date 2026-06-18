class Solution {
public:

    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>> qt;
        qt.push({"0000",0});

        set<string> visited , donotVisit;
        visited.insert("0000");

        for(auto x : deadends) donotVisit.insert(x);

        while(!qt.empty()){
            
            string curr = qt.front().first;
            int level = qt.front().second;
            qt.pop();

            if(curr == target) return level;
            if(donotVisit.find(curr) != donotVisit.end()) continue;      

            for(int i=0;i<4;i++){

                char increaseCh = (char)('0' + ((curr[i]-'0')+1)%10);
                char decreaseCh = (char)('0' + ((10 + (curr[i]-'0') - 1)%10));

                string increase = curr, decrease = curr; 
                increase[i] = increaseCh;
                decrease[i] = decreaseCh;

                if(visited.find(increase) == visited.end()){
                    qt.push({increase,level+1});
                    visited.insert(increase);
                }

                if(visited.find(decrease) == visited.end()){
                    qt.push({decrease,level+1});
                    visited.insert(decrease);
                }
            }

        }

        return -1;
    }
};