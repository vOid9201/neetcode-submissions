class Solution {
public:
    int solve(int i,int amount,vector<int>& coins,vector<vector<int>>&dp){
        if(i < 0 and amount > 0) return 0;
        if(amount == 0) return 1;
        if(dp[i][amount] != -1) return dp[i][amount];
        if(amount >= coins[i])
            dp[i][amount] = solve(i-1,amount,coins,dp)+solve(i,amount-coins[i],coins,dp);
        else
            dp[i][amount] = solve(i-1,amount,coins,dp);
        return dp[i][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};
