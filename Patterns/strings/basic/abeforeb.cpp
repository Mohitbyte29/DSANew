class Solution {
public:
    bool checkString(string s) {
        bool check = true;
        for(int i = 0; i < s.size(); i++){
            if(check == false && s[i] == 'a') return false;
            if(s[i] == 'b') check = false; 
        }
        return true;
    }
};