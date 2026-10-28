class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while(i < n && s[i] != 'b'){
            i++;
        }
        while(j >= 0 && s[j] != 'a'){
            j--;
        }
        stack<int> st;
        int cnt = 0;
        while(j >= i){
             if (s[j] == 'a') {
                st.push(j);
            } else if (!st.empty()) {  
                st.pop();
                cnt++;
            }   
            j--;
        }
        return cnt;
    }
};