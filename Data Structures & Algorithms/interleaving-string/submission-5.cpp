class Solution {
public:

int solve(int i,int j,string s1,string s2,string s3,vector<vector<int>>&dp){
	//base condition 
	if(i < 0 and j < 0) return 1;
	if(i < 0){
		while(j >= 0 and s2[j] == s3[j]) j--;
		if(j<0)return 1;
		return 0;
	}
	if(j < 0){
		while(i >= 0 and s1[i] == s3[i]) i--;
		if(i<0)return 1;
		return 0;
	}
	
	if(dp[i][j] != -1) return dp[i][j];
	int ans = 0;
	
	if(s1[i] == s3[i+j+1]) ans |= solve(i-1,j,s1,s2,s3,dp);
	if(s2[j] == s3[i+j+1]) ans |= solve(i,j-1,s1,s2,s3,dp);
	
	return dp[i][j] = ans;
}

bool isInterleave(string s1,string s2,string s3){
	int n = s1.size() , m = s2.size();
	if(n+m != (int)s3.size()) return false;
	vector<vector<int>> dp(n,vector<int>(m,-1));
	return solve(n-1,m-1,s1,s2,s3,dp);
}
};
