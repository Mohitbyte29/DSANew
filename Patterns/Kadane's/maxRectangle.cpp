class Solution {
    int kadane(vector<int> &arr){
        int curr = arr[0];
        int best = arr[0];
        for(int i = 1; i < arr.size(); i++){
            curr = max(arr[i], curr + arr[i]);
            best = max(curr, best);
        }
        return best;
    }
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        int ans = INT_MIN;
        for(int left = 0; left < n; left++){
            vector<int> rowSum(m, 0);
            for(int right = left; right < n; right++){
                for(int row = 0; row < m; row++){
                    rowSum[row] += mat[row][right];
                }
                ans = max(ans, kadane(rowSum));
            }
        }
        return ans;
    }
};
