#include <iostream>
#include <vector>
using namespace std;

int main() {
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
    void unionByRank(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu == pv) return;
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
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        int V = edges.size();
        DisjointSet ds(n);
        for(int i = 0; i < V; i++){
            ds.unionByRank(edges[i][0], edges[i][1]);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i){
                cnt++;
            }
        }
        if(V < n - 1) return -1;
        return cnt - 1;
    }
};