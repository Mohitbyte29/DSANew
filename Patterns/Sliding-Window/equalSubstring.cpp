class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int left = 0, right = 0;
        int diff = 0, maxDiff = INT_MIN;
        int length = 0;
        while(right < n){
            diff += abs((s[right] - 'a') - (t[right] - 'a'));
            while(diff > maxCost){
                diff -= abs((s[left] - 'a') - (t[left] - 'a'));
                left++;
            }
            length = right - left + 1;
            maxDiff = max(maxDiff, length);
            right++;
        }
        return maxDiff;
    }
};