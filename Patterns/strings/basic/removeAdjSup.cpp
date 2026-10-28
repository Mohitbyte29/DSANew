class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string res = "";
        for(int i = 0; i < s.size(); i++){
            if(!st.empty()){
                if(s[i] == st.top()){
                    st.pop();
                    continue;
                }
            }
            st.push(s[i]);
        } 
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};