class Solution{
public:
    int subarraysWithXorK(vector<int> &a, int k) {
        unordered_map<int, int> mp;
        int xr = 0, cnt = 0;
        mp[0] = 1;
        for(int i = 0; i < a.size(); i++){
            xr ^= a[i];
            int x = xr ^ k;
            cnt += mp[x];
            mp[xr]++;
        }
        return cnt;
    }
};