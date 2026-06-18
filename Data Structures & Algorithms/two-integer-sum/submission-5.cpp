class Solution {
public:

    void partition(vector<int> &nums,int l,int &pivot,int r){
        vector<int> left , right;
        int value = nums[pivot];
        for(int i=l;i<=r;i++){
            if(i == pivot) continue;
            if(nums[i] <= value) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        int k = l;
        for(int x : left){
            nums[k] = x;
            k ++;
        }
        nums[k] = value;
        pivot = k++;
        for(int x : right){
            nums[k] = x;
            k ++; 
        }
        return;
    }

    void quickSort(vector<int> &nums,int l,int r){
        if(r<=l) return ;
        int p = r;
        partition(nums,l,p,r);
        quickSort(nums,l,p-1);
        quickSort(nums,p+1,r);
        return;
    }

    void merge(vector<int> &nums,int l,int mid,int r){
        int n = mid - l + 1 , m = r - mid;
        vector<int> left(n) , right(m);
        for(int i=l;i<=r;i++){
            if(i<=mid) left[i-l] = nums[i];
            else right[i-(mid+1)] = nums[i];
        }
        int i = 0 , j = 0 , k = l;
        while(i<n && j < m){
            if(left[i] < right[j]){
                nums[k] = left[i];
                i ++ ;
            }else{
                nums[k] = right[j];
                j ++;
            }
            k++;
        }
        while(i<n){
            nums[k] = left[i];
            k ++ , i ++;
        }
        while(j<m){
            nums[k] = right[j];
            k ++ , j ++;
        }
        return;
    }

    void mergeSort(vector<int> &nums,int l,int r){
        if(r<=l) return;
        int mid = (l+r)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        merge(nums,l,mid,r);
        return;
    }

    void insertionSort(vector<int> &nums){
        int n = (int)nums.size();
        for(int sorted_len=1;sorted_len<n;sorted_len++){
            int key = nums[sorted_len];
            int j = sorted_len -1 ;
            while(j>=0 && nums[j] > key){
                nums[j+1] = nums[j];
                j -- ;
            }
            nums[j+1] = key;
        }
        return;
    }

    void bubbleSort(vector<int> &nums){
        int n = (int)nums.size();
        for(int pass=1;pass<n;pass++){
            for(int i=0;i<n-pass;i++){
                if(nums[i] > nums[i+1]){
                    int t = nums[i];
                    nums[i] = nums[i+1];
                    nums[i+1] = t;
                }
            }
        }
        return ;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int>> mp;
        int n = (int)nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        // bubbleSort(nums);
        // insertionSort(nums);
        mergeSort(nums,0,n-1);
        int i = 0 , j = n -1;
        while(i < j){
            if(target == (nums[i] + nums[j])) break;
            if(target < (nums[i] + nums[j])) j-- ;
            else i ++ ;
        }
        if(mp[nums[i]][0] < mp[nums[j]].back())
            return {mp[nums[i]][0] , mp[nums[j]].back()};
        return {mp[nums[j]].back() , mp[nums[i]][0]};
    }
};
