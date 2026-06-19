class Solution {
public:

int findTargetSumWays(vector<int>&nums,int target){
	int total_sum = 0ll , n = nums.size();
	for(auto x : nums) total_sum += x;
	vector<vector<int>> dp(n+1,vector<int>(2*total_sum+1,0));
	dp[0][0+total_sum] = 1;
	for(int i=1;i<n+1;i++){
		for(int j=0;j<2*total_sum+1;j++){
			if(dp[i-1][j] == 0) continue;
			else{
				dp[i][j+nums[i-1]] += dp[i-1][j];
				dp[i][j-nums[i-1]] += dp[i-1][j];
			}
		}
	}
	
	if(target+total_sum >=0 and target+total_sum < 2*total_sum+1)
		return dp[n][target+total_sum];
	return 0;
}
};
