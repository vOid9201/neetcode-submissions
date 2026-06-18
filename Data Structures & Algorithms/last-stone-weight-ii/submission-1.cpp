class Solution {
public:
int solve(int i,int weight,vector<int>&stones,vector<vector<int>>&dp){
	if(i<0) return 0;
	if(i>=0 and weight == 0) return dp[i][weight] = 0;
	
	if(dp[i][weight] != -1) return dp[i][weight];
	
	if(stones[i] <= weight)
		dp[i][weight] = max(stones[i]+solve(i-1,weight-stones[i],stones,dp) , 
		solve(i-1,weight,stones,dp));
	else 
		dp[i][weight] = solve(i-1,weight,stones,dp);
	return dp[i][weight];	
}

int lastStoneWeightII(vector<int>&stones){
	int n = stones.size();
	int totalWeight = 0ll;
	for(auto x : stones) totalWeight += x;
	int oneSubsetUpperLimit = totalWeight/2;
	vector<vector<int>> dp(n,vector<int>(oneSubsetUpperLimit+1,-1));
	return abs(totalWeight - 2*solve(n-1,oneSubsetUpperLimit,stones,dp));
}
};