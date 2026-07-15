Memoization
class Solution {
    int f(int ind, int w, int n, vector<int> &val, vector<int> &wt, vector<vector<int>>& dp){
        if(w == 0 || ind < 0){
            return 0;
        }
        if(dp[ind][w] != -1){
            return dp[ind][w];
        }
        int skip = f(ind - 1, w, n, val, wt, dp);
        int take = 0;
        if(wt[ind] <= w){
            take = val[ind] + f(ind - 1, w - wt[ind], n, val, wt, dp);
        }
        
        return dp[ind][w] = max(take, skip);
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        return f(n - 1, W, n, val, wt, dp);
    }
};

Tabulation
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        for(int w = wt[0]; w <= W; w++) dp[0][w] = val[0];
        
        for(int ind = 1; ind<n; ind++){
            for(int w = 0; w <= W; w++){
                int skip = 0 + dp[ind - 1][w];
                int take = INT_MIN;
                if(wt[ind] <= w){
                    take = val[ind] + dp[ind - 1][w - wt[ind]];
                }
                dp[ind][w] = max(take, skip);
            }
        }
        return dp[n - 1][W];
    }
};