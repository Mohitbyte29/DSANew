// Brute(TLE)
class Solution {
public:
    string minWindow(string s, string t) {
        long long minLen = INT_MAX, sIndex = -1;
        int n = s.size(), m = t.size();
        for(int i = 0; i < n; i++){
            int hash[256] = {0}, count = 0;
            for(int j = 0; j<m; j++) hash[t[j]]++;
            for(int j = i; j<n; j++){
                if(hash[s[j]] > 0) count++;
                hash[s[j]]--;
                if(count == m){
                if(j - i + 1 < minLen){
                    minLen = j - i + 1;
                    sIndex = i;
                    break;
                }
            }
            }
        }
        if(sIndex == -1) return "";
        return s.substr(sIndex, minLen);
    }
};

// Best
class Solution {
public:
    string minWindow(string s, string t) {
        long long minLen = INT_MAX, sIndex = -1;
        int n = s.size(), m = t.size();
        int count = 0;
        int l = 0, r = 0, hash[256] = {0};
        for(char c : t){
            hash[c]++;
        }
        while(r < n){
            if(hash[s[r]] > 0) {
                count++;
            };
                hash[s[r]]--;
            while(count == m){
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)count--; 
                l++;
            }
            r++;
        }
        if(sIndex == -1) return "";
        return s.substr(sIndex, minLen);
    }
};