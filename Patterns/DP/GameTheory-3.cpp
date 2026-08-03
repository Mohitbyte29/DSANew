class Solution {
public:
    string stoneGameIII(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n + 1, INT_MIN);
        dp[n] = 0;
        for(int i = n - 1; i >= 0; i--){
            int take = 0;
            for(int k = 0; k < 3 && (i + k) < n; k++){
                take += arr[i + k];
                dp[i] = max(dp[i], take - dp[i + k + 1]);
            }
        }
        if(dp[0] == 0) return "Tie";
        return dp[0] > 0 ? "Alice":"Bob";
    }
};