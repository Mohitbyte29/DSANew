class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while(low <= high){
            int mid = low + (high - low)/2;
            int stuNo = findSum(arr, mid);
            if(stuNo > k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
    int findSum(vector<int> &arr, int pages){
        int stu = 1, pagesStudent = 0;
        for(int i = 0; i<arr.size(); i++){
            if(pagesStudent + arr[i] <= pages){
                pagesStudent += arr[i];
            }
            else{
                stu++;
                pagesStudent = arr[i];
            }
        }
        return stu;
    }
};