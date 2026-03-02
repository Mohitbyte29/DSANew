//* Best Approach

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastSeen[3] = {-1, -1, -1};
        int cnt = 0;

        for (int i = 0; i < s.size(); i++) {
            lastSeen[s[i] - 'a'] = i;

            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                int mn = min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
                cnt += (mn + 1);
            }
        }

        return cnt;
    }
};

int main() {
    Solution obj;
    string s = "abcabc";
    cout << obj.numberOfSubstrings(s) << endl;
    return 0;
}