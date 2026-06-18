class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() , m = text2.size();
        vector<int> prev(m+1,0);

        for(int i=0;i<n+1;i++){
            vector<int> temp(m+1,0);
            for(int j=0;j<m+1;j++){
                if(i == 0 or j == 0) temp[j] = 0;
                else{
                    if(text1[i-1] == text2[j-1]) temp[j] = 1 + prev[j-1];
                    else temp[j] = max(temp[j-1] , prev[j]);
                }
            }
            prev = temp;
        }

        return prev[m];
    }
};
