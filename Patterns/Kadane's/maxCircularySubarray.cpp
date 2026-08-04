class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        int currMax = 0;
        int maxSum = INT_MIN;

        int currMin = 0;
        int minSum = INT_MAX;

        for(int x : arr){
            currMax = max(x, x + currMax);
            maxSum = max(maxSum, currMax);

            currMin = min(x, x + currMin);
            minSum = min(minSum, currMin);

            total += x;
        }

        if(maxSum < 0)
            return maxSum;

        return max(maxSum, total - minSum);
    }
};