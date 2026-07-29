//* Recursion
class Solution {
    bool isPalindrome(string &temp){
        int n = temp.size();
        int i = 0, j = n - 1;
        while(i <= j){
            if(temp[i] != temp[j]) return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    int solve(int i, int n, string& s){
        if(i == n) return 0;
        string temp = "";
        int minCost = INT_MAX;
        for(int j = i; j < n; j++){
            temp += s[j];
            if(isPalindrome(temp)){
                int cost = 1 + solve(j + 1, n, s);
                minCost = min(minCost, cost);
            }
        }
        return minCost;
    }
public:
    int minCut(string s) {
        int n = s.size();
        return solve(0, n, s) - 1;
    }
};

//* Memoization
class Solution {
    bool isPalindrome(string &temp){
        int n = temp.size();
        int i = 0, j = n - 1;
        while(i <= j){
            if(temp[i] != temp[j]) return false;
                i++;
                j--;
        }
        return true;
    }
    int solve(int i, int n, string& s, vector<int>& dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        string temp = "";
        int minCost = INT_MAX;
        for(int j = i; j < n; j++){
            temp += s[j];
            if(isPalindrome(temp)){
                int cost = 1 + solve(j + 1, n, s, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, n, s, dp) - 1;
    }
};