// Recursion
class Solution {
    int f(int i, int j, string& s, string& t){
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;
        if(s[i] == t[j]) return f(i - 1, j - 1, s, t);
        return 1 + min(f(i, j - 1, s, t), min(f(i - 1, j, s, t), f(i - 1, j - 1, s, t)));
    }
public:
    int minDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        return f(m - 1, n - 1, s, t);
    }
};

// Memoization
class Solution {
    int f(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = f(i - 1, j - 1, s, t, dp);
        return dp[i][j] = 1 + min(f(i, j - 1, s, t, dp), min(f(i - 1, j, s, t, dp), f(i - 1, j - 1, s, t, dp)));
    }
public:
    int minDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return f(m - 1, n - 1, s, t, dp);
    }
};

// Tabulation
class Solution {
public:
    int minDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for(int i = 0; i<=m; i++) dp[i][0] = i;
        for(int j = 0; j <= n; j++) dp[0][j] = j;
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j] , dp[i - 1][j - 1]});
                }
            }
        }
        return dp[m][n];
    }
};