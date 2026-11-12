class DisjointSet{
    public:
    vector<int> parent, rank;
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    int findPar(int node){
        if(parent[node] == node) return node;
        else return parent[node] = findPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int ult_u = findPar(u);
        int ult_v = findPar(v);
        if(ult_u == ult_v) return;
        if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_u] > rank[ult_v]){
            parent[ult_v] = ult_u;
        }
        else{
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& edges) {
        int V = edges.size();
        DisjointSet ds(V);
        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                if(edges[i][j] == 1){
                    ds.unionByRank(i, j);
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < V; i++){
            if(ds.parent[i] == i){
                cnt++;
            }
        }
        return cnt;
    }
};