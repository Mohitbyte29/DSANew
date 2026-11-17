class DisjointSet {
public:
    vector<int> rank, parent;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;   // fixed: i <= n
    }
    int findPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }
    bool unionByRank(int u, int v) {
        int pu = findPar(u), pv = findPar(v);
        if (pu == pv) return false;
        if (rank[pu] == rank[pv]) {
            rank[pu]++;
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n + 1, 0);
        vector<int> cand1, cand2;

        // Step 1: detect a node with two parents
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            if (par[v] != 0) {
                cand1 = {par[v], v};   // earlier edge into v
                cand2 = {u, v};        // later edge into v
                break;
            }
            par[v] = u;
        }

        // Step 2: DSU, skipping cand2
        DisjointSet ds(n);
        for (auto& e : edges) {
            if (!cand2.empty() && e == cand2) continue;
            if (!ds.unionByRank(e[0], e[1])) {
                // cycle detected
                if (!cand1.empty()) return cand1;
                return e;
            }
        }
        return cand2;   // no cycle after skipping cand2
    }
};