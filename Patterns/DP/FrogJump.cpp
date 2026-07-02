// For 2 distances
class Solution {
    int solve(vector<int>& height, vector<int>& dp, int i){
        if(i == 0) return 0;
        if(dp[i] != -1) return dp[i];
        int left = solve(height, dp, i - 1) + abs(height[i] - height[i - 1]);
        int right = INT_MAX;
        if(i > 1){
            right = solve(height, dp, i - 2) + abs(height[i] - height[i - 2]);
        }
        return dp[i] = min(left, right);
    }
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n + 1, -1);
        return solve(height, dp, n - 1);
    }
};

//! For K distances
class Solution {
    int solve(vector<int>& height, vector<int>& dp, int i, int k) {
        if (i == 0)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;

        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                ans = min(ans,
                          solve(height, dp, i - j, k) +
                          abs(height[i] - height[i - j]));
            }
        }

        return dp[i] = ans;
    }

public:
    int minimizeCost(vector<int>& height, int k) {
        int n = height.size();
        vector<int> dp(n, -1);

        return solve(height, dp, n - 1, k);
    }
};