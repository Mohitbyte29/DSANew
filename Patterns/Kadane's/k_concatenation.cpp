class Solution {
    const int MOD = 1e9 + 7;
    long long kadane(vector<int>& arr){
        long long curr = 0;
        long long best = 0;

        for(long long x : arr){
            curr = max(x, x + curr);
            best = max(curr, best);
        }
        return best;
    }
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if(k == 1){
            return kadane(arr) % MOD;
        }
        long long total = 0;

        long long prefix = 0;
        long long maxPrefix = 0;

        long long suffix = 0;
        long long maxSuffix = 0;

        for(int x : arr){
            total += x;
            prefix += x;
            maxPrefix = max(prefix, maxPrefix);
        }
        for(int i = arr.size() - 1; i >= 0; i--){
            suffix += arr[i];
            maxSuffix = max(suffix, maxSuffix);
        }
        long long ans = 0;
        ans = maxPrefix + maxSuffix;
        if(total > 0){
            ans += (k - 2)*total;
        }
        ans = max(ans, kadane(arr));
        return ans % MOD;
    }
};