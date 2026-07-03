** By Memoization but gives TLE
class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int i, vector<int>& nums, vector<int>& dp){
        if(i == 0) return max(nums[0], 0);
        if(i < 1) return 0;

        if(dp[i] != -1)
            return dp[i];

        int take = nums[i] + solve(i - 2, nums, dp);
        int skip = 0 + solve(i - 1, nums, dp);
        return dp[i] = max(take, skip);
    }

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        long long ans = 0;
        int n = nums.size();
        for(auto &q : queries){
            nums[q[0]] = q[1];
            vector<int> dp(n + 1, -1);
            ans = (ans + solve(n - 1, nums, dp)) % MOD;
        }
        return ans;
    }
};

By Tabulation
    
class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int n = nums.size();
        for(auto &q : queries){
            nums[q[0]] = q[1];
            vector<int> dp(n + 1);
            dp[0] = max(0, nums[0]);
            for(int i = 1; i < n; i++){
                int take = nums[i];
                if(i > 1){
                    take += dp[i - 2];
                }
                int skip = 0 + dp[i - 1];
                dp[i] = max(take, skip);
            }
   ans = (ans + dp[n - 1]) % MOD;
        }
        return ans;
    }
};

Space Optimization
    
class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int n = nums.size();
        for(auto &q : queries){
            nums[q[0]] = q[1];
            vector<int> dp(n + 1);
            int prev = max(0, nums[0]);
            int prev2 = 0;
            for(int i = 1; i < n; i++){
                int take = nums[i] + prev2;
                int skip = 0 + prev;
                int curi = max(take, skip);
                prev2 = prev;
                prev = curi;
            }
                ans = (ans + prev) % MOD;
        }
        return ans;
    }
};