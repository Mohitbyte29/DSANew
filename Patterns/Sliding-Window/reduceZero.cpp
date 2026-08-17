class Solution {
public:
    int minOperations(vector<int>& arr, int x) {
        int n = arr.size();
        int left = 0, right = 0;
        int ans = -1, res = 0;
        int length = 0;
        int total = 0;
        for(int x : arr){
            total += x;
        }
        int target = total - x;
        if(target < 0) return -1;
        if(target == 0) return n;
        while(right < n){
            res += arr[right];
            while(res > target){
                res -= arr[left];
                left++;
            }
            if(res == target) {
                length = right - left + 1;
                ans = max(length, ans);
            }
            right++;
        }
        if(ans == -1) return -1;
        return n - ans;
    }
};