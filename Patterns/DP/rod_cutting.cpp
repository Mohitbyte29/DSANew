Memoization
class Solution {
    int f(int ind, int target, vector<int> &arr, vector<vector<int>>& dp){
        if(ind == 0){
            return (target * arr[ind]);
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int take = INT_MIN;
        int skip = 0 + f(ind - 1, target, arr, dp);
        int rodLength = ind + 1;
        if(rodLength <= target){
            take = arr[ind] + f(ind, target - rodLength, arr, dp);
        }
        return dp[ind][target] = max(take, skip);
    }
  public:
    int cutRod(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return f(n - 1, n, arr, dp);
    }
};

Tabulation
class Solution {
  public:
    int cutRod(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, 0));
        for(int N = 0; N <= n; N++){
            dp[0][N] = N * arr[0];
        }
        
        for(int ind = 1; ind < n; ind++){
            for(int N = 0; N <= n; N++){
                int take = INT_MIN;
                int skip = 0 + dp[ind - 1][N];
                int rodLength = ind + 1;
                if(rodLength <= N){
                    take = arr[ind] + dp[ind][N - rodLength];
                }
                dp[ind][N] = max(take, skip);
            }
        }
        return dp[n - 1][n];
    }
};