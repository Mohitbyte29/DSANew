class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        int i = 0;
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n - 2; i++){
            if (i > 0 && a[i] == a[i - 1]) continue;
            int j = i + 1, k = n - 1;
            while(j < k){
                int sum = a[i] + a[j] + a[k]; 
                if(sum == 0){
                     ans.push_back({a[i], a[j], a[k]});
                     j++;
                     k--;
                     while(j < k && a[j] == a[j - 1]) j++;
                     while(j < k && a[k] == a[k + 1]) k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};