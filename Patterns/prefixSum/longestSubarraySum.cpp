//* Brute

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> res(n, 0);
        vector<int> prefix(n, 0);
        prefix[0] = arr[0];
        for(int i = 0; i < n - 1; i++){
            prefix[i + 1] = prefix[i] + arr[i + 1];
        }
        if(prefix[n - 1] == k) return n;
        int maxAns = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int sum;
                
                if(i == 0) sum = prefix[j];
                else{
                    sum = prefix[j] - prefix[i - 1];
                }
                
                if(sum == k){
                    maxAns = max(maxAns, j - i + 1);
                }
            }
        }
        return maxAns;
    }
};

//* Optimum
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mp;
        int sum = 0, maxLen = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            
            if(sum == k){
                maxLen = i + 1;
            }
            
            int rem = sum - k;
            
            if(mp.find(rem) != mp.end()){
                maxLen = max(maxLen, i - mp[rem]);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;    
            }
        }
        return maxLen;
    }
};
