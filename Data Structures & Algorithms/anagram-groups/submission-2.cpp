class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string x : strs){
            vector<int> freq(26,0);
            for(char ch:x){
                freq[ch-'a'] ++;
            }

            string key = "";
            for(int x : freq){
                key += to_string(x) + "#";
            }

            mp[key].push_back(x);
        }

        vector<vector<string>> res;
        for(auto it=mp.begin();it!=mp.end();it++){
            vector<string> temp;
            for(auto x : it->second)
                temp.push_back(x);
            res.push_back(temp);
        }

        return res;
    
    }
};
