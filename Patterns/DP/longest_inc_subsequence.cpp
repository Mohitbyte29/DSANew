// Memoization
class Solution {
    int f(int i, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(i == nums.size()) return 0;
        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
        int take = INT_MIN;
        int skip = f(i + 1, prev, nums, dp);
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1 + f(i + 1, i, nums, dp);
        }
        return dp[i][prev + 1] = max(take, skip);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return f(0, -1, nums, dp);
    }
};

// Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[i] > nums[prev]){
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

// Binary Search
class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp;
        temp.push_back(arr[0]);
        int len = 1;
        for(int i = 1; i < n; i++){
            if(arr[i] > temp.back()){
                temp.push_back(arr[i]);
                len++;
            }
            else{
                auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
                *it = arr[i];
            }
        }
        return len;
    }
};