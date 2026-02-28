//! Better By map method
class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n = arr.size();
        int count = 1;
        unordered_map<int, int> mpp;
        int r = 0, l = 0, len = 0;
        int maxLen = 0;
        while(r < n){
                mpp[arr[r]]++;
            while(mpp.size() > 2){
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0){
                    mpp.erase(arr[l]);
                }
                l++;
            }
            len = r - l + 1;
            maxLen = max(len, maxLen);
            r++;
        }
        return maxLen;
    }
};

//! Best 
class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n = arr.size();
        int count = 1;
        unordered_map<int, int> mpp;
        int r = 0, l = 0, len = 0;
        int maxLen = 0;
        while(r<n){
            mpp[arr[r]]++;
            if(mpp.size() > 2){
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0){
                    mpp.erase(arr[l]);
                }
                l++;
            }
            if(mpp.size() <= 2){
                len = r - l + 1;
                maxLen = max(len, maxLen);
            }
                r++;
        }
        return maxLen;
    }
};