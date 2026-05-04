#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid[0].size(), n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;
        int ans = 0;

        // Push all rotten oranges
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }
        
        // BFS traversal
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();

            ans = max(ans, time);

            if(i - 1 >= 0 && !vis[i - 1][j] && grid[i - 1][j] == 1){
                q.push({{i - 1, j}, time + 1});
                vis[i - 1][j] = true;
            }
            if(j + 1 < m && !vis[i][j + 1] && grid[i][j + 1] == 1){
                q.push({{i, j + 1}, time + 1});
                vis[i][j + 1] = true;
            }
            if(i + 1 < n && !vis[i + 1][j] && grid[i + 1][j] == 1){
                q.push({{i + 1, j}, time + 1});
                vis[i + 1][j] = true;
            }
            if(j - 1 >= 0 && !vis[i][j - 1] && grid[i][j - 1] == 1){
                q.push({{i, j - 1}, time + 1});
                vis[i][j - 1] = true;
            }
        }

        // Check if any fresh orange remains
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    return -1;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int result = obj.orangesRotting(grid);
    cout << "Time to rot all oranges: " << result << endl;

    return 0;
}