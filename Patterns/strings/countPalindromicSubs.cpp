class Solution {
    long long mod = 1e9 + 7;
    bool isPalindrome(string& s){
        int n = s.size();
        int i = 0, j = n - 1;
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int n, string& ans, string& s){
        if(ans.size() == 5){
            return isPalindrome(ans);
        }
        if(n == s.size()){
            return 0;
        }
        if(ans.size() + (s.size() + n) < 5) return 0;
        ans.push_back(s[n]);
        long long take = f(n + 1, ans, s);
        ans.pop_back();
        long long skip = f(n + 1, ans, s);
        return (take + skip) % mod;
    }
public:
    int countPalindromes(string s) {
        int n = s.size();
        if(n < 5) return 0;
        string ans = "";
        return f(0, ans, s);
    }
};