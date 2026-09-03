class Solution {
public:
    bool uniformArray(vector<int>& a) {
        int n = a.size();
        int minOdd = INT_MAX;
        for(auto& x:a){
            if(x % 2 == 1){
                minOdd = min(minOdd, x);
            }
        }
        if(minOdd == INT_MAX) return true;
        for(int x : a){
            if(x % 2 == 0 && x < minOdd){
                return false;
            }
        }
        return true;
    }
};