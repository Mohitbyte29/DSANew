//* Best
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMost(vector<int>& arr, int goal){
        if(goal < 0) return 0;

        int l = 0, sum = 0, ans = 0;

        for(int r = 0; r < arr.size(); r++){
            sum += arr[r];

            while(sum > goal){
                sum -= arr[l++];
            }

            ans += (r - l + 1);
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& arr, int goal) {
        return atMost(arr, goal) - atMost(arr, goal - 1);
    }
};

int main() {
    Solution s;
    vector<int> arr = {1,0,1,0,1};
    int goal = 2;

    cout << s.numSubarraysWithSum(arr, goal);
    return 0;
}