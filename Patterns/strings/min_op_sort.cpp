class Solution {
    bool isSorted(string s){
        int n = s.size();
        for(int i = 1; i < n; i++){
            if(s[i] < s[i - 1]) return false;
        }
        return true;
    }
public:
    int minOperations(string s) {
        int n = s.size();
        if(isSorted(s)) return 0;
        if(n == 2) return -1;
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());
        if(s[0] == mn || s[n - 1] == mx) return 1;
        for(int i = 1; i < n - 1; i++){
            if(s[i] == mn || s[i] == mx) return 2;
        }
        return 3;
    }
};