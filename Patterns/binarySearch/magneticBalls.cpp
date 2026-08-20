class Solution {
public:
    int maxDistance(vector<int>& arr, int m) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int ans = 1;
        sort(arr.begin(), arr.end());
        while(low <= high){
            int mid = low + (high - low)/2;
            if(canPlace(arr, mid, m)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }

    bool canPlace(vector<int>& arr, int dist, int balls){
        int cont = 1;
        int lastPlaced = arr[0];
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - lastPlaced >= dist){
                cont++;
                lastPlaced = arr[i];
            }
            if(cont >= balls){
                return true;
            }
        }
        return false;
    }
};