Recursion
class Solution {
    int f(int i, int buy, vector<int>& prices, int n){
        if(i == n) return 0;
        long profit = 0;
        if(buy){
            profit = max(-prices[i] + f(i + 1, 0, prices, n), 0 + f(i + 1, 1, prices, n));
        }
        else{
            profit = max(prices[i] + f(i + 1, 1, prices, n), 0 + f(i + 1, 0, prices, n));
        }
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return f(0, 1, prices, n);
    }
};

Memoization
class Solution {
    int f(int i, int buy, vector<int>& prices, int n, vector<vector<int>>& dp){
        if(i == n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy){
            dp[i][buy] = max(-prices[i] + f(i + 1, 0, prices, n, dp), 0 + f(i + 1, 1, prices, n, dp));
        }
        else{
            dp[i][buy] = max(prices[i] + f(i + 1, 1, prices, n, dp), 0 + f(i + 1, 0, prices, n, dp));
        }
        return dp[i][buy];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
         vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, n, dp);
    }
};

Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
         vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for(int i = n - 1; i >= 0; i--){
            dp[i][1] = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
            dp[i][0] = max(prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
        }
        return dp[0][1];
    }
};