class DisjointSet{
    public:
        vector<int> parent, size;
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
    bool isValid(int newr, int newc, int n){
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};

                for(int ind = 0; ind<4; ind++){
                    int newr = dr[ind] + row;
                    int newc = dc[ind] + col;
                    if(isValid(newr, newc, n) && grid[newr][newc] == 1){
                        int node = row * n + col;
                        int adjNode = newr * n + newc;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        int mx = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                set<int> components;
                for(int ind = 0; ind<4; ind++){
                    int newr = dr[ind] + row;
                    int newc = dc[ind] + col;
                    if(isValid(newr, newc, n) && grid[newr][newc] == 1){
                        components.insert(ds.findPar(newr * n + newc));
                    }
                }
                int sizeTotal = 1;
                for(auto it:components){
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal);
            }
        }
        for(int cellNo = 0; cellNo < n * n; cellNo++){
            mx = max(mx, ds.size[ds.findPar(cellNo)]);
        }
        return mx;
    }
};