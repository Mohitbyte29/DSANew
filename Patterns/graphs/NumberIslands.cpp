#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    void bfs(int row, int col,
             vector<vector<int>>& vis,
             vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        vis[row][col] = 1;
        q.push({row, col});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {

                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < m &&
                   ncol >= 0 && ncol < n &&
                   !vis[nrow][ncol] &&
                   grid[nrow][ncol] == '1') {

                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int cnt = 0;

        for(int row = 0; row < m; row++) {

            for(int col = 0; col < n; col++) {

                if(grid[row][col] == '1' &&
                   vis[row][col] == 0) {

                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }

        return cnt;
    }
};

int main() {

    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    Solution obj;

    cout << "Number of Islands: "
         << obj.numIslands(grid);

    return 0;
}