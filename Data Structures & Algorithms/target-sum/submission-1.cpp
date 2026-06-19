class Solution {
public:

    int solve(int i,int target,int posNegIndicator,vector<int>&nums,
    vector<vector<vector<int>>>&dp){
        if(i < 0 and target != 0) return 0;
        if(target == 0 and i < 0) return 1;
        if(dp[i][abs(target)][posNegIndicator] != -1) 
            return dp[i][abs(target)][posNegIndicator];

        return dp[i][abs(target)][posNegIndicator] = 
        solve(i-1,target+nums[i],(target+nums[i]>=0) ? 1 : 0,nums,dp) + 
        solve(i-1,target-nums[i],(target-nums[i])>=0 ? 1 : 0,nums,dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(30001,vector<int>(2,-1)));
        return solve(n-1,target,(target >= 0) ? 1 : 0,nums,dp);
    }
};
