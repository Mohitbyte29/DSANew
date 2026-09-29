class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < 3; i++){
            ans += arr[i];
        }
        for(int i = 0; i < n - 2; i++){
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                int sum = arr[i] + arr[left] + arr[right];
                if(abs(sum - target) < abs(ans - target)){
                    ans = sum; 
                }
                if(sum < target){
                    left++;
                }
                else if(sum > target){
                    right--;
                }
                else{
                    return sum;
                }
            }
        }
        return ans;
    }
};