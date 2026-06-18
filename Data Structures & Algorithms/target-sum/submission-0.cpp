#include<bits/stdc++.h>

class Solution {
public:
    int solve(vector<int>&nums,int i,int sum,int target,map<pair<int,int>,int>& mp){
        if(i == (int)nums.size()){
            return (int)(sum == target);
        }
        if(mp.find({i,sum})!=mp.end()) return mp[{i,sum}];

        int ans = 0;
        ans = solve(nums,i+1,sum+nums[i],target,mp) + solve(nums,i+1,sum-nums[i],target,mp);

        return mp[{i,sum}] = ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int> mp;
        return solve(nums,0,0,target,mp);
    }
};
