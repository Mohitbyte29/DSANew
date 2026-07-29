class Solution {
    int solve(int i, int j, int isTrue, string& s, vector<vector<vector<int>>>& dp){
        if(i > j) return 0;
        if(i == j){
            if(isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        long long ways = 0;
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        for(int ind = i + 1; ind <= j - 1; ind += 2){
            int lt = solve(i, ind - 1, 1, s, dp);
            int lf = solve(i, ind - 1, 0, s, dp);
            int rt = solve(ind + 1, j, 1, s, dp);
            int rf = solve(ind + 1, j, 0, s, dp);
            
            if(s[ind] == '&'){
                if(isTrue) ways += lt * rt;
                else ways += lt * rf + lf * rt + lf * rf;
            }
            else if(s[ind] == '|'){
                if(isTrue) ways += lt * rf + lf * rt + lt * rt;
                else ways += lf * rf;
            }
            else if(s[ind] == '^'){
                if(isTrue) ways += lt * rf + lf * rt;
                else ways += lt * rt + lf * rf;
            }
        }
        return dp[i][j][isTrue] = ways;
    }
  public:
    int countWays(string &s) {
        // code here
        int n = s.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (n + 1, vector<int> (2, -1)));
        return solve(0, n - 1, 1, s, dp);
    }
};