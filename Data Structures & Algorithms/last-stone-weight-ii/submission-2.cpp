class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
	int n = stones.size();
	int totalWeight = 0ll;
	for(auto x : stones) totalWeight += x;
	int subsetUpperLimit = totalWeight/2;
	vector<vector<int>> dp(n+1,vector<int>(subsetUpperLimit+1,-1));
	
	for(int i=0;i<n+1;i++) dp[i][0] = 0;
	for(int i=0;i<subsetUpperLimit+1;i++) dp[0][i] = 0;
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<subsetUpperLimit+1;j++){
			if(stones[i-1] <= j)
				dp[i][j] = max(stones[i-1]+dp[i-1][j-stones[i-1]],dp[i-1][j]);
			else 
				dp[i][j] = dp[i-1][j];
		}
	}
	
	return abs(totalWeight - 2*dp[n][subsetUpperLimit]);
}
};