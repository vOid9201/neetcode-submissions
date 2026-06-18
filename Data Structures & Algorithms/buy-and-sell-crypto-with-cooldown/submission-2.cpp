class Solution {
public:
int solve(int i,int sellBuyIndicator,vector<int> &prices, vector<vector<int>>&dp){
	if(i < 0 and sellBuyIndicator == 0) return 0;
	if(i < 0 and sellBuyIndicator == 1) return INT_MIN;
	
	if(dp[i][sellBuyIndicator] != -1) return dp[i][sellBuyIndicator];
	
	if(sellBuyIndicator == 0){
		int sold = solve(i-1,1,prices,dp);
		int notSold = solve(i-1,0,prices,dp);
		dp[i][sellBuyIndicator] = max(sold == INT_MIN ? INT_MIN :
		prices[i]+sold , notSold);
	}else{
		int bought = solve(i-2,0,prices,dp);
		int notBought = solve(i-1,1,prices,dp);
		dp[i][sellBuyIndicator] = max( bought == INT_MIN ? INT_MIN : 
		bought - prices[i] , notBought);
	}
	
	return dp[i][sellBuyIndicator];
}

int maxProfit(vector<int>&prices){
	int n = prices.size();
	vector<vector<int>> dp(n,vector<int>(2,-1));
	return solve(n-1,0,prices,dp);
}
};
