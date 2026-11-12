class DisjointSet{
public:
    vector<int> rank, parent;
    DisjointSet(int n){
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int findPar(int node){
        if(parent[node] == node) return node;
        else return parent[node] = findPar(parent[node]);
    }
    bool unionByRank(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu == pv) return true;
        else{
            if(rank[pu] == rank[pv]){
                rank[pu]++;
                parent[pv] = pu;
            }
            else if(rank[pu] < rank[pv]){
                parent[pu] = pv;
            }
            else{
                parent[pv] = pu;
            }
            return false;
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        DisjointSet ds(n);
        for(int i = 0; i < edges.size(); i++){
            ds.unionByRank(edges[i][0], edges[i][1]);
        }
        return ds.unionByRank(s, d);
    }
};