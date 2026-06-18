class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int x : nums){
            mp[x] ++ ;
        }

        vector<vector<int>> res(n+1);
        for(auto it=mp.begin();it!=mp.end();it++){
            res[it->second].push_back(it->first);
        }

        vector<int> ans;
        for(int i=n;i>=0;i--){
            for(auto x : res[i]){
                ans.push_back(x);
                k --;
                if(k == 0)
                    break;
            }
            if(k == 0) break;
        }

        return ans;
    }
};
