//* Memoization
class Solution {
     int f(int ind, int w, int n, vector<int> &val, vector<int> &wt, vector<vector<int>>& dp){
        if(ind == 0){
            return (w / wt[0]) * val[0];
        }
        if(dp[ind][w] != -1){
            return dp[ind][w];
        }
        int skip = f(ind - 1, w, n, val, wt, dp);
        int take = 0;
        if(wt[ind] <= w){
            take = val[ind] + f(ind, w - wt[ind], n, val, wt, dp);
        }
        
        return dp[ind][w] = max(take, skip);
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
        return f(n - 1, capacity, n, val, wt, dp);
    }
};