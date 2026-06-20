class Solution {
public:

    int solve(int i,int j,string s1,string s2,string s3,
    vector<vector<int>> &dp){
        //base-condition 
        if(i < 0 and j < 0 and i+j+1 < 0) return 1;
        if(i == -1){
            while(j >= 0 and s2[j] == s3[j]) j --;
            if(j == -1) return 1;
            return 0;
        }
        if(j == -1){
            while(i >= 0 and s1[i] == s3[i]) i --;
            if(i == -1) return 1;
            return 0;
        }
        // if(ind == 1 and s3[i+j+1] != s1[i]) return 0;
        // if(ind == 2 and s3[i+j+1] != s2[j]) return 0;
        //have to check against first s1
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s1[i] == s3[i+j+1])
            ans |= solve(i-1,j,s1,s2,s3,dp);
        if(s2[j] == s3[i+j+1])
            ans |= solve(i,j-1,s1,s2,s3,dp);
        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size() , m = s2.size() , k = s3.size();
        if(k != n+m) return false;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s1,s2,s3,dp) == 1 ? true : false;
    }
};
