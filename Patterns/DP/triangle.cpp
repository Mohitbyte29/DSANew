// Memoization
class Solution {
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp, int n){
        if(i == n - 1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = f(i + 1, j, triangle, dp, n);
        int diag = f(i + 1, j + 1, triangle, dp, n);
        return dp[i][j] = triangle[i][j] + min(down, diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return f(0, 0, triangle, dp, n);
    }
};

// Tabulation
class Solution {
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        for(int j = 0; j<n; j++) 
            dp[n - 1][j] = triangle[n - 1][j];
        for(int i = n - 2; i>=0; i--){
            for(int j = i; j>=0; j--){
                int down = dp[i + 1][j];
                int diag = dp[i + 1][j + 1];
                dp[i][j] = triangle[i][j] + min(down, diag);
            }
        }
        return dp[0][0];
    }
};