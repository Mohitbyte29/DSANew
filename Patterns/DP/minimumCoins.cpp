Memoization
class Solution {
    int f(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0){
            if(target % coins[0] == 0) return target/coins[0];
            return 1e9;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int skip = 0 + f(ind - 1, target, coins, dp);
        int take = INT_MAX;
        if(coins[ind] <= target){
            take = 1 + f(ind, target - coins[ind], coins, dp);
        }
        return dp[ind][target] = min(take, skip);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, -1));
        int ans = f(n - 1, amount, coins, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};
Tabulation
class Solution {
    int f(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0){
            if(target % coins[0] == 0) return target/coins[0];
            return 1e9;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int skip = 0 + f(ind - 1, target, coins, dp);
        int take = INT_MAX;
        if(coins[ind] <= target){
            take = 1 + f(ind, target - coins[ind], coins, dp);
        }
        return dp[ind][target] = min(take, skip);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, 0));
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0) dp[0][i] = i / coins[0];
            else dp[0][i] = 1e9;  
        }

        for(int ind = 1; ind <n; ind++){
            for(int T = 0; T <= amount; T++){
                int skip = 0 + dp[ind - 1][T];
                int take = INT_MAX;
                if(coins[ind] <= T){
                    take = 1 + dp[ind][T - coins[ind]];
                }
                dp[ind][T] = min(take, skip);
            }
        }
        int ans = dp[n - 1][amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};