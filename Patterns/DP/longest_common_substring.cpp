class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int m = s1.size();
        int n = s2.size();
        int ans = 0;
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for(int i = 0; i<=m; i++) dp[i][0] = 0;
        for(int j = 0; j<=n; j++) dp[0][j] = 0;
        
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};

Space Optimized
class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int m = s1.size();
        int n = s2.size();
        int ans = 0;
        vector<int> prev(n + 1, 0), cur(n + 1, 0);
        
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(s1[i - 1] == s2[j - 1]){
                    cur[j] = 1 + prev[j - 1];
                    ans = max(ans, cur[j]);
                }
                else{
                    cur[j] = 0;
                }
            }
            prev = cur;
        }
        return ans;
    }
};