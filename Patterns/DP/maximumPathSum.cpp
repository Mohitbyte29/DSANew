class Solution {
    int f(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& mat, int m){
        if(j < 0 || j >= m)
            return 0;
        if(i == 0)
            return mat[0][j];
        if(dp[i][j] != -1) return dp[i][j];
        int leftDiag = f(i - 1, j - 1, dp, mat, m);
        int up = f(i - 1, j, dp, mat, m);
        int rightDiag = f(i - 1, j + 1, dp, mat, m);
        return dp[i][j] = mat[i][j] + max(leftDiag, max(rightDiag, up));
    }
  public:
    int maximumPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int ans = 0;
        for(int j = 0; j<m; j++){
            ans = max(ans, f(n - 1, j, dp, mat, m));
        }
        return ans;
    }
};
