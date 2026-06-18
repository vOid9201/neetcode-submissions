class Solution {
public:
    int maxProfit(vector<int>&prices){
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,-1));
        
        for(int i=0;i<2;i++) dp[i][1] = INT_MIN , dp[i][0] = 0;
        
        for(int i=2;i<n+2;i++){
            dp[i][0] = max( dp[i-1][1] == INT_MIN ? INT_MIN : dp[i-1][1]+prices[i-2],
            dp[i-1][0]);
            dp[i][1] = max( dp[i-2][0] == INT_MIN ? INT_MIN : dp[i-2][0]-prices[i-2],
            dp[i-1][1]);
        }
        
        return max(dp[n+1][0],dp[n+1][1]);
    }
};
