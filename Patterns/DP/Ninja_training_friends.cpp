Memoization
class Solution {
    int f(int i, int j, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int m, int n){
        if(j < 0 || j >= m || k < 0 || k >= m) return -1e8;
        if(i == n - 1){
            if(j == k) return grid[i][j];
            else return grid[i][j] + grid[i][k];
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int maxi = -1e8;
        for(int j1 = -1; j1 <= 1; j1++){
            for(int j2 = -1; j2 <= 1; j2++){
                int value = 0;
                if(j == k) value = grid[i][j];
                else value = grid[i][j] + grid[i][k];
                value += f(i + 1, j + j1, k + j2, grid, dp, m, n);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j][k] = maxi;
    }
  public:
    int maxChocolate(vector<vector<int>>& grid) {
        // code here
        int m = grid[0].size(), n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return f(0, 0, m - 1, grid, dp, m, n);
    }
};

Tabulation
class Solution {

  public:
    int maxChocolate(vector<vector<int>>& grid) {
        // code here
        int m = grid[0].size(), n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        for(int j = 0; j < m; j++){
            for(int k = 0; k < m; k++){
                if(j == k) dp[n - 1][j][k] = grid[n - 1][j];
                else dp[n - 1][j][k] = grid[n - 1][j] + grid[n - 1][k];
            }
        }
        
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < m; k++){
                    int maxi = -1e8;
                    for(int j1 = -1; j1<=1; j1++){
                        for(int j2 = -1; j2 <= 1; j2++){
                            int value = 0;
                            if(j == k) value = grid[i][j];
                            else value = grid[i][j] + grid[i][k];
                            if(j + j1 >= 0 && j + j1 < m && k + j2 >= 0 && k + j2 < m)
                            {
                                value += dp[i + 1][j + j1][k + j2];
                            }
                            else{
                                value += -1e8;
                            } 
                                maxi = max(maxi, value);
                        }
                    }
                     dp[i][j][k] = maxi;
                }
            }
        }
        return dp[0][0][m - 1];
    }
};