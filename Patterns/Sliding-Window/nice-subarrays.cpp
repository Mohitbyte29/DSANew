
#include <iostream>
#include <vector>
using namespace std;

// Brute(TLE)
class Solution {
public:
    int numberOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        if(k > n) return 0;
        for(int i = 0; i <= n - k; i++){
            int cnt = 0;
            for(int j = i; j < n; j++){
                if(arr[j] % 2 == 1){
                    cnt++;
                }
                if(cnt == k){
                    ans++;
                }
            }
        }
        return ans;
    }
};

// Best
class Solution {
public:
    int atMost(vector<int>& arr, int k){
        int n = arr.size();
        int ans = 0, count = 0;
        int l = 0, r = 0;
        while(r < n){
            ans += (arr[r] % 2);
            while(ans > k){
                ans = ans - (arr[l] % 2);
                l++;
            }
            count = count + (r - l + 1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& arr, int k) {
        return atMost(arr, k) - atMost(arr, k - 1);
    }
};

int main() {
    Solution obj;

    vector<int> arr = {1, 1, 2, 1, 1};
    int k = 3;

    int result = obj.numberOfSubarrays(arr, k);

    cout << "Number of subarrays with exactly " << k << " odd numbers: " << result << endl;

    return 0;
}