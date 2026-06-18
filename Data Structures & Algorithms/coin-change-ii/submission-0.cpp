class Solution {
    int solve(vector<int> &coins ,int i,int amount,vector<vector<int>>&dp){
        if(i <  0 and amount > 0) return 0;
        if(amount == 0) return 1;

        if(dp[i][amount] != -1) return dp[i][amount];

        if(amount >= coins[i])
            dp[i][amount] = solve(coins,i,amount-coins[i],dp) + solve(coins,i-1,amount,dp);
        else 
            dp[i][amount] = solve(coins,i-1,amount,dp);

        return dp[i][amount];

    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        return solve(coins,n-1,amount,dp);
    }
};
