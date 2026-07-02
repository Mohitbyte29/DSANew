class Solution {
  public:
    void floydWarshall(vector<vector<int>> &arr) {
        // Code here
        int n = arr.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(arr[i][j] == -1){
                    arr[i][j] = 1e9;
                }
                if(i == j) arr[i][j] = 0;
            }
        }
        
        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if (arr[i][k] == 1e9 || arr[k][j] == 1e9)
                        continue;
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(arr[i][j] == 1e9){
                    arr[i][j] = -1;
                }
            }
        }
        
    }
};
it gives wrong answer