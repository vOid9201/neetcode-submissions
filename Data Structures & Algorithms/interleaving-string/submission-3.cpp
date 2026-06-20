class Solution {
public:

    int solve(int i,int j,string s1,string s2,string s3,int ind,
    vector<vector<vector<int>>> &dp){
        //base-condition 
        if(i < 0 and j < 0 and i+j+1 < 0) return 1;
        if(i == -1){
            while(j >= 0 and s2[j] == s3[j]) j --;
            if(j == -1) return true;
            else return false;
        }
        if(j == -1){
            while(i >= 0 and s1[i] == s3[i]) i --;
            if(i == -1) return true;
            return false;
        }
        if(ind == 1 and s3[i+j+1] != s1[i]) return 0;
        if(ind == 2 and s3[i+j+1] != s2[j]) return 0;
        cout << i << " " << j << " " << i+j+1 << '\n';
        //have to check against first s1
        if(dp[i][j][ind] != -1) return dp[i][j][ind];
        int ans = 0;
        if(ind == 1){
                ans = (solve(i-1,j,s1,s2,s3,1,dp) | solve(i-1,j,s1,s2,s3,2,dp));
        }else if(ind == 2){
                ans = (solve(i,j-1,s1,s2,s3,1,dp) | solve(i,j-1,s1,s2,s3,2,dp));
        }else{
            if(s3[i+j+1] == s1[i])
                ans = (solve(i-1,j,s1,s2,s3,1,dp) | solve(i-1,j,s1,s2,s3,2,dp));
            if(s3[i+j+1] == s2[j])
                ans = (solve(i,j-1,s1,s2,s3,1,dp) | solve(i,j-1,s1,s2,s3,2,dp));
        }
        // dp[i][j][ind] = val == true ? 1 : 0;
        // return ans;
        return dp[i][j][ind] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size() , m = s2.size() , k = s3.size();
        if(k != n+m) return false;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(3,-1)));
        return solve(n-1,m-1,s1,s2,s3,0,dp) == 1 ? true : false;
    }
};
