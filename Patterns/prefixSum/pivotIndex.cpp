class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return -1;
        int left = 0, right = 0;
        if(left == 0 && arr[1] == 0) return 0;
        for(int i = 1; i < n; i++){
            right += arr[i];
        }
        for(int i = 0; i < n - 1; i++){
            if(left == right) return i;
            left += arr[i];
            right -= arr[i + 1];
        }
        if(left == right) return (n - 1);
        return -1;
    }
};