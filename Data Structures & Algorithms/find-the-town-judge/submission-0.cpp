class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> countOfPeopleWhoTrust(n+1,0);
        vector<int> countOfPeopleWhoItTrust(n+1,0);

        for(auto x : trust){
            countOfPeopleWhoTrust[x[1]] ++;
            countOfPeopleWhoItTrust[x[0]] ++;
        }

        for(int i=1;i<=n;i++){
            if(countOfPeopleWhoTrust[i] == n-1 and countOfPeopleWhoItTrust[i] == 0) return i;
        }

        return -1;
    }
};