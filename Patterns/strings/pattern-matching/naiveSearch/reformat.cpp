class Solution {
public:
    string reformat(string s) {
        int n = s.size();
        string a = "", d = "";
        for(auto x:s){
            isalpha(x) ? a.push_back(x) : d.push_back(x);
        }
        if(abs(int(a.size()-d.size()))>1)
            return "";
        bool alpha=a.size()>d.size();
        int i=0,j=0,k=0;
            while(i<s.size()){
                if(alpha){
                    s[i++]=a[j++];
                }
                else{
                    s[i++]=d[k++];
                }
                alpha=!alpha;
            }
        return s;
    }
};