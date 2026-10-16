class Solution {
public:
    string simplifyPath(string path) {
        stack<char> st;
        int n = path.size();
        int i = 0;
        while(i < n){
            while(i < n && path[i] == '/') i++;
            if(i >= n) break;
            string comp = "";
            while(i < n && path[i] != '/'){
                comp += path[i];
                i++;
            }
            if(comp == "."){
                continue;
            }
            else if(comp == ".."){
                while (!st.empty() && st.top() != '/') st.pop();
                if (!st.empty()) st.pop();
            }
            else{
                st.push('/');
                for(char c : comp) st.push(c);
            }
        }
        if(st.empty()) return "/";
        string result = "";
        while(!st.empty()){
            result += st.top();     
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};