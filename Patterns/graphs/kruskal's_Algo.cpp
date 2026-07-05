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
  public:
    static bool comp(vector<int> &a, vector<int>& b){
        return a[2] < b[2];
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        DisjointSet ds(V);
        sort(edges.begin(), edges.end(), comp);
        int minWt = 0;
        
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(ds.findPar(u) != ds.findPar(v)){
                minWt += wt;
                ds.unionBySize(u, v);
            }
        }
        
        return minWt;
    }
};