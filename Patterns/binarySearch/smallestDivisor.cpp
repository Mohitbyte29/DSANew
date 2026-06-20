class Solution {
public:
    int smallestDivisor(vector<int>& arr, int threshold) {
        int low = 1;
        int n = arr.size();
        long long high = *max_element(arr.begin(), arr.end());
        while(low <= high){
            int mid = low + (high - low)/2;
            int res = 0;
            for(int i = 0; i<n; i++){
                res += ceil(double(arr[i])/double(mid));
            }
                if(res <= threshold){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
        return low;
    }
};