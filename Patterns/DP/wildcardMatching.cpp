class Solution {
    int f(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i < 0 && j < 0) return true;
        if(i >= 0 && j < 0) return false;
        if(i < 0 && j >= 0){
            for(int ii = 0; ii <= j; ii++){
                if(p[ii] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);
        }
        if(p[j] == '*'){
            return dp[i][j] = f(i, j - 1, s, p, dp) || f(i - 1, j, s, p, dp);
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return f(m - 1, n - 1, s, p, dp);
    }
};