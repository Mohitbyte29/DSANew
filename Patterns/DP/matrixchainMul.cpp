//* Memoization
class Solution {
    int f(int i, int j, vector<int>& arr, vector<vector<int>> &dp){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int k = i; k < j; k++){
            int steps = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
            if(steps < mini){
                mini = steps;
            }
        }
        return dp[i][j] = mini;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return f(1, n - 1, arr, dp);
    }
};

//* Tabulation
class Solution {
public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // i starts from n-1 because we are filling from smaller chains to larger
        for (int i = n - 1; i >= 1; i--) {
            for (int j = i + 1; j < n; j++) {

                int mini = 1e9;

                for (int k = i; k < j; k++) {
                    int steps = arr[i - 1] * arr[k] * arr[j]
                              + dp[i][k]
                              + dp[k + 1][j];

                    mini = min(mini, steps)
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][n - 1];
    }
};