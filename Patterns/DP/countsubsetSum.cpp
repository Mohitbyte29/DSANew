//* Memoization
class Solution {
    int f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
        // if(target == 0) return 1;
        if(ind == 0){
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }
        if(target < 0) return 0;
        if(dp[ind][target] != -1) return dp[ind][target];
        int notTake = f(ind - 1, target, arr, dp);
        int take = 0;
        if(target >= arr[ind]){
            take = f(ind - 1, target - arr[ind], arr, dp);
        }
        const int MOD = 1e9 + 7;
        return dp[ind][target] = (take + notTake) % MOD;
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n - 1, target, arr, dp);
    }
};