class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int j = 1; j <= n/2; j++){
            if(n % j != 0) continue;
            string text = s.substr(0, j);
            bool valid = true;

            for(int i = j; i < n; i += j){
                if(text != s.substr(i, j)){
                    valid = false;
                    break;
                }
            }
            if(valid) return true;
        }
        return false;
    }
};