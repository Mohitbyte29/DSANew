Brute(TLE)
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        int n = arr.size();
        int cnt = 0;
        for(int i = 0; i <= n - k; i++){
            map<int,int> mpp; 
            for(int j = i; j<n; j++){
                mpp[arr[j]]++;
                if(mpp.size() == k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

Best
class Solution {
public:
    int atMost(vector<int>& arr, int k){
        int n = arr.size();
        int cnt = 0;
        int l = 0, r = 0;
        unordered_map<int, int> mpp;
        while(r < n){
            mpp[arr[r]]++;
            while(mpp.size() > k){
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0){
                    mpp.erase(arr[l]);
                }
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        return atMost(arr, k) - atMost(arr, k - 1);
    }
};