class Solution {
public:
    int solve(vector<int>& prices , int i, int canBuy,vector<vector<int>>&dp){
        if(i >= (int)prices.size()) return 0;
        if(dp[i][canBuy] != -1) return dp[i][canBuy];

        if(canBuy == 1) dp[i][canBuy] =  max(-prices[i]+solve(prices,i+1,0,dp), solve(prices,i+1,canBuy,dp));
        else dp[i][canBuy] = max(prices[i]+solve(prices,i+2,1,dp),solve(prices,i+1,canBuy,dp));

        return dp[i][canBuy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};
