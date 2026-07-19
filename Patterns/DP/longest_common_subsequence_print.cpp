// Tabulation
class Solution {
  public:
    vector <int> lcs(string &s1, string &s2) {
        // code here
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for(int i = 0; i<=m; i++) dp[i][0] = 0;
        for(int j = 0; j<=n; j++) dp[0][j] = 0;
        
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        } 
        int len = dp[m][n];
        string s = "";
        for(int i = 0; i <= len; i++) s += '$';
        int i = m, j = n;
        while(i > 0 && j > 0){
                if(s1[i - 1] == s2[j - 1]){
                        s[index] = s1[i - 1];
                        index--;
                }
                else if(dp[i - 1][j] > dp[i][j - 1]){
                        i = i - 1;
                }
                else {
                        j = j - 1;
                }
        return s;
    }
};