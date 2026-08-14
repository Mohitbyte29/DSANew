class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        if(k > n) return 0;
        int maxAns = 0, num = 0;
        int left = 0, right = k;
        int total = 0, ans = 0;
        for(int i = 0; i < k; i++){
            total += arr[i];
        }
        maxAns = double(total/k);
        if(maxAns >= threshold) ans++;
        while(right < n){
            total += arr[right] - arr[left];
            if(double(total/k) >= threshold) ans++;
            left++, right++;
        }
        return ans;
    }
};