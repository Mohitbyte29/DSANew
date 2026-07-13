
//! Memoization
class Solution {
    bool f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind == 0) return (arr[0] == target);
        if(dp[ind][target] != -1) return dp[ind][target];
        bool notTake = f(ind - 1, target, arr, dp);
        bool take = false;
        
        if(target >= arr[ind]){
            take = f(ind - 1, target - arr[ind], arr, dp);
        }
        return dp[ind][target] = take | notTake;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int> (target + 1, -1));
        return f(n - 1, target, arr, dp);
    }
};

//! Tabulation
class Solution {
    
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool> (target + 1, 0));
        for(int i = 0; i<n; i++){
            dp[i][0] = true;
        }
        dp[0][arr[0]] = true;
        for(int ind = 1; ind < n; ind++){
            for(int sum = 1; sum <= target; sum++){
                bool notTake = dp[ind - 1][sum];
                bool take = false;
        
                if(sum >= arr[ind]){
                    take = dp[ind - 1][sum - arr[ind]];
                }   
                dp[ind][sum] = take || notTake;
            }
        }
        return dp[n - 1][target];
    }
};

//! Space Optimization
class Solution {
    
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<bool> prev(target + 1, 0), curr(target + 1, 0);
        prev[0] = curr[0] = true;
        prev[arr[0]] = true;
        for(int ind = 1; ind < n; ind++){
            for(int sum = 1; sum <= target; sum++){
                bool notTake = prev[sum];
                bool take = false;
        
                if(sum >= arr[ind]){
                    take = prev[sum - arr[ind]];
                }   
                curr[sum] = take || notTake;
            }
            prev = curr;
        }
        return prev[target];
    }
};