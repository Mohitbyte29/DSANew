class Solution {
    int kadane(vector<int>& rowSum, int k){
        int prefix = 0, best = INT_MIN;
        set<int> st;
        st.insert(0);
        for(int x : rowSum){
            prefix += x;
            auto it = st.lower_bound(prefix - k);
            if(it != st.end()){
                best = max(best, prefix - *it);
            }
            st.insert(prefix);
        }
        return best;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& arr, int k) {
        int m = arr.size();
        int n = arr[0].size();
        int ans = INT_MIN;
        for(int left = 0; left < n; left++){
            vector<int> rowSum(m, 0);
            for(int right = left; right < n; right++){
                for(int row = 0; row < m; row++){
                    rowSum[row] += arr[row][right];
                }
                ans = max(ans, kadane(rowSum, k));
            }
        }
        return ans;
    }
};