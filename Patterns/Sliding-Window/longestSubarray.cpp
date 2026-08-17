class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        unordered_map<int, int> mpp;
        int ans = 0, length = 0;
        int n = nums.size();
        while(right < n){
            mpp[nums[right]]++;
            while(mpp[0] > 1){
                mpp[nums[left]]--;
                left++;
            }
            length = right - left + 1;
            ans = max(ans, length);
            right++;
        }
        return ans - 1;
    }
};