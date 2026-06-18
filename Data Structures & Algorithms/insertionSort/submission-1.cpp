// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> res ;
        int n = pairs.size();
        if(n==0) return res;
        res.push_back(pairs);
        for(int i=1;i<n;i++){
            Pair p = pairs[i];
            int key = pairs[i].key;
            int j = i -1;
            while(j >=0 && pairs[j].key > key){
                pairs[j+1] = pairs[j];
                j--;
            }
            pairs[j+1] = p;
            res.push_back(pairs);
        }

        return res;
    }
};
