class Solution {
public:
    int lengthOfLongestSubstring(string arr) {
        int n = arr.size();
        unordered_set<char> mpp;
        if(arr.empty()) return 0;
        int len = 1, maxLen = 1;
        int l = 0;
        for(int r = 0; r<n; r++){
            while(mpp.find(arr[r]) != mpp.end()){
                mpp.erase(arr[l]);
                l++;
            }
            mpp.insert(arr[r]);
            len = r - l + 1;
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};


