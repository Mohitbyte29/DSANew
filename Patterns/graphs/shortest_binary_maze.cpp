class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        if(mat[src[0]][src[1]] == 0)
    return -1;
        if(src == dest)
    return 0;
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[src[0]][src[1]] = 0;
        q.push({0, {src[0], src[1]}});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!q.empty()){
            auto it = q.front();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            q.pop();
            for(int i = 0; i<4; i++){
                int newr = dr[i] + r;
                int newc = dc[i] + c;
                
                if(newr >= 0 && newr < n && newc >= 0 &&  newc < m && mat[newr][newc] == 1 &&
                dis + 1 < dist[newr][newc]){
                    dist[newr][newc] = dis + 1;
                    if(newr == dest[0] && newc == dest[1]) return dis + 1;
                    q.push({1 + dis, {newr, newc}});
                }
            }
        }
        return -1;
    }
};
