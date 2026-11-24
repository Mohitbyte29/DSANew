class Solution {
    long long gcd(long long a, long long b){
        while(b) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b){
        return (a / gcd(a, b)) * b;
    }
public:
    int maxLength(vector<int>& a) {
        int n = a.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++){
            long long curr_prod = 1;
            long long curr_gcd = a[i];
            long long curr_lcm = a[i];

            for(int j = i; j < n; j++){
                if (curr_prod > 1000000000000LL / a[j]) {
                    curr_prod = 2000000000000LL;
                } else {
                    curr_prod *= a[j];
                }
                if(j > i){
                    curr_gcd = gcd(curr_gcd, a[j]);
                    curr_lcm = lcm(curr_lcm, a[j]);
                } 
                if(curr_prod == curr_lcm * curr_gcd){
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};