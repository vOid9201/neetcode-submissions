class Solution {
public:

    bool checkOrder(string left, string right , unordered_map<char,int>&mp){
        int n = left.size() , m = right.size();
        int i = 0;
        for(i;i<min(n,m);i++){
            if(mp[left[i]] == mp[right[i]]) continue;
            if(mp[left[i]] > mp[right[i]]) return false;
            else return true;
        }

        if(i < n) return false;
        return true;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        for(int i=0;i<(int)order.size();i++){
            mp[order[i]] = i;
        }

        for(int i=0;i<(int)words.size()-1;i++){
            if(!checkOrder(words[i],words[i+1],mp))
                return false;
        }

        return true;
    }
};