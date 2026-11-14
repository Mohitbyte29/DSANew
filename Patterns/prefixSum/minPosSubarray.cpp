#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& a, int l, int r) {
        int n = a.size();
        int minAns = INT_MAX;
        for(int i = 0; i <= n - l; i++){
            int ans = 0;
            for(int j = i; j < n && j < i + r; j++){
                ans += a[j];
            int len = j - i + 1;
                if(len >= l && len <= r && ans > 0){
                    minAns = min(minAns, ans);
                } 
            }
        }
        return minAns == INT_MAX ? -1 : minAns;
    }
};