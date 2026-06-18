class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> charac(26,0);
        for(char ch : s) charac[ch-'a']++;
        for(char ch : t) charac[ch-'a']--;
        for(int freq : charac){
            if(freq != 0) return false;
        }
        return true;
    }
};
