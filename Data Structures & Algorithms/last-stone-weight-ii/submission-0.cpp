class Solution {
public:

    int solve(vector<int>& stones,int i,int w,vector<vector<int>> &dp){
        //base - condition 
        if( i < 0 ) return 0;
        if( i>=0 and w == 0) return dp[i][w] = 0;

        //to prevent recalculation 
        if(dp[i][w] != -1) return dp[i][w];
        
        //recursive calls 
        if(stones[i] <= w)
            dp[i][w] = max(solve(stones,i-1,w-stones[i],dp)+stones[i] , 
            solve(stones,i-1,w,dp));
        else 
            dp[i][w] = solve(stones,i-1,w,dp);
        return dp[i][w];
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = (int)stones.size();
        int totalWeight  = 0;
        for(auto x : stones) totalWeight += x;
        int upperLimitWeight = (totalWeight/2);
        vector<vector<int>> dp(n,vector<int>(upperLimitWeight+1,-1));
        return abs(totalWeight - 2*solve(stones,n-1,upperLimitWeight,dp));
    }
};