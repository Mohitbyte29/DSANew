class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int prefixSum = 0, count = 0;
        for(int i = 0; i < a.size(); i++){
            prefixSum += a[i];
            int remove = prefixSum - k;
            if(mpp.find(remove) != mpp.end()){
                count += mpp[remove];
            }
            mpp[prefixSum]++;
        }        
        return count;
    }
};