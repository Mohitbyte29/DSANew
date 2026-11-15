class DisjointSet{
    public:
    vector<int> rank, parent;
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int findPar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    bool unionByRank(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu == pv) return false;
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
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        DisjointSet ds(V);
        for (auto& e : edges)
            if (!ds.unionByRank(e[0], e[1])) return {e[0], e[1]};
        return {};
    }
};