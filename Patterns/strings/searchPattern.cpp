class Solution {
public:
    vector<int> search(string &pat, string &txt) {
        int n = txt.size();
        int m = pat.size();

        vector<int> ans;

        for (int i = 0; i <= n - m; i++) {
            int j = 0;

            while (j < m && txt[i + j] == pat[j]) {
                j++;
            }

            if (j == m) {
                ans.push_back(i); 
            }
        }

        return ans;
    }
};