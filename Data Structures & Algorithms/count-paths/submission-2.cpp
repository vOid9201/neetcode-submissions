class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,1);

        for(int i=0;i<m;i++){
            vector<int> temp(n,1);
            for(int j=0;j<n;j++){    
                if(i == 0 or j == 0) continue;
                else temp[j] = prev[j] + temp[j-1];
            }
            prev = temp;
        }

        return prev[n-1];
    }
};
