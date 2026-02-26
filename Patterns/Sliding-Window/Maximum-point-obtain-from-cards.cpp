class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> newArr(arr.begin(), arr.end());
        
        int sum = 0;
        for(int i = 0; i<k; i++){
            sum += arr[i]; 
        }
        int maxSum = sum;
        for(int i = 1; i <= k; i++){
            sum -= arr[k - i];       
            sum += arr[n - i];   
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};

