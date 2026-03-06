// Brute
for(int i = 0; i<n; i++){
int hash[3] = {0};
for(int j = 1; j<n; j++){
hash[s[j] - 'a'] = 1;
if( hash[0] + hash[1] + hash[2] == 3){
cnt = cnt + (n - j), break;
}
}
}
return cnt;

// Best
class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastSeen[3] =  {-1, -1, -1};
        int cnt = 0;
        for(int i = 0 ; i<s.size(); i++){
            lastSeen[s[i] - 'a'] = i;
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
                int mn = min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
                cnt += (1 + mn);
            }
        }
        return cnt;
    }
};