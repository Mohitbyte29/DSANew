class Solution {
public:
    int maxAbsoluteSum(vector<int>& arr) {
        int maxSum = INT_MIN, n = arr.size();
        int currMax = 0, currMin = 0;
        int minSum = INT_MAX;
        for(int x : arr){
            currMax = max(x, currMax + x);
            maxSum = max(maxSum, currMax);

            currMin = min(x, currMin + x);
            minSum = min(minSum, currMin);
        }
        int ans = 0;
        ans = max(abs(maxSum), abs(minSum));
        return ans;
    }
};