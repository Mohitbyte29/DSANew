class Solution {
         int f(int i, int buy, vector<int>& prices, int n,int fee, vector<vector<int>>& dp){
        if(i == n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy){
            dp[i][buy] = max(-prices[i] + f(i + 1, 0, prices, n, fee, dp), 0 + f(i + 1, 1, prices, n, fee, dp));
        }
        else{
            dp[i][buy] = max(prices[i] + f(i + 1, 1, prices, n, fee, dp) - fee, 0 + f(i + 1, 0, prices, n, fee, dp));
        }
        return dp[i][buy];
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, n, fee, dp);
    }
};