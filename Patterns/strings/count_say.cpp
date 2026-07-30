/* Run-length encoding (RLE) is a string compression method that works by replacing each maximal
 group of consecutive identical characters with the concatenation of the length of the group followed by 
 the character itself. For example, to compress
  the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5"
   with "15", and replace "1" with "11". Thus the compressed string becomes "23321511".*/

class Solution {
    string rle(string s, int i, int n){
        if(i == n) return s;
        string ans = "";
        int len = 1; 
        char prev = s[0];
        for(int j = 0; j < s.size() - 1; j++){
            if(s[j] == s[j + 1]){
                len++;
            }
            else{
                ans += to_string(len);
                ans += prev;
                len = 1;
                prev = s[j + 1];
            }
        }
        ans += to_string(len);
        ans += prev;

        return rle(ans, i + 1, n);
    }
public:
    string countAndSay(int n) {
        return rle("1", 1, n);
    }
};

