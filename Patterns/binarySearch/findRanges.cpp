//* By BinarySearch (Ologn)
class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;
        auto lb = lower_bound(arr.begin(), arr.end(), target);
        auto ub = upper_bound(arr.begin(), arr.end(), target);
        if (lb == arr.end() || *lb != target) 
            return {-1, -1};
        else{
            int first = lb - arr.begin();
            int last = ub - arr.begin() - 1;
            return {first, last};
        }
    }
};

//* By 2 Pointers Approach (O(n))
class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        vector<int> ans;
        int i = 0, j = a.size() - 1;
        while(i <= j){
            if(a[i] != target){
                i++;
            }
            if(a[j] != target){
                j--;
            }
            if(i <= j && a[i] == target && a[j] == target){
                return {i, j};
            }
        }
        return {-1, -1};
    }
};