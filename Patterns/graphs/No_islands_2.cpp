class DisjointSet{
        vector<int> parent, size;
    public:
        DisjointSet(int n){
            parent.resize(n + 1);
            size.resize(n + 1);
            for(int i = 0; i<=n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findPar(int node){
            if(node == parent[node]){
                return node;
            }
            else return parent[node] = findPar(parent[node]);
        }

        void unionBySize(int u, int v){
            int ult_u = findPar(u);
            int ult_v = findPar(v);
            if(ult_u == ult_v) return;
            if(size[ult_u] < size[ult_v]){
                parent[ult_u] = ult_v;
                size[ult_v] += size[ult_u];
            }
            else{
                parent[ult_v] = ult_u;
                size[ult_u] += size[ult_v];
            }
        }
};


class Solution {
    bool isValid(int adjRow, int adjCol, int m, int n){
        return adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < m;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(m * n);
        int vis[n][m];
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        vector<int> ans;
        
        for(auto it:operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for(int ind = 0; ind < 4; ind++){
                int adjRow = dr[ind] + row;
                int adjCol = dc[ind] + col;
                
                if(isValid(adjRow, adjCol, m, n)){
                    if(vis[adjRow][adjCol] == 1){
                        int node = row * m + col;
                        int adjNode = adjRow * m + adjCol;
                        if(ds.findPar(node) != ds.findPar(adjNode)){
                            cnt--;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
