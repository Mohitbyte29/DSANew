class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int ,pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq ;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        int dr[] = {0, -1, 0, 1};
        int dc[] = {1, 0, -1, 0};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(dis > dist[r][c]) continue;
            if(r == n - 1 && c == m - 1) return dis;
            for(int i = 0; i<4; i++){
                int nrow = r + dr[i];
                int ncol = c + dc[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    int newEffort = max(abs(heights[r][c] - heights[nrow][ncol]), dis);
                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};