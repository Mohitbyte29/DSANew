class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string str = "";
        for(char x : s){
            if(isalnum(x)) str += tolower(x);
        }
        int i = 0, j = str.size() - 1;
        while(i <= j){
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};