class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long curr = 0;
        long res = 0;
        int sign = 1;

        for(char ch : s){
            if(isdigit(ch)){
                curr = curr * 10 + (ch - '0');
            }
            else if(ch == '+'){
                res += sign * curr;
                sign = 1;
                curr = 0;
            }
            else if(ch == '-'){
                res += sign * curr;
                sign = -1;
                curr = 0;
            }
            else if(ch == ')'){
                res += sign * curr;
                curr = 0;
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
            }
            else if(ch == '('){
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
        }
        res += sign * curr;
        return res;
    }
};