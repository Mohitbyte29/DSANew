#include <iostream>
#include <vector>
using namespace std;

class DisjointSet{
        vector<int> rank, parent, size;
    public:
        DisjointSet(int n){
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            size.resize(n + 1);
            for(int i = 0; i<n; i++){
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

        void unionByRank(int u, int v){
            int ult_u = findPar(u);
            int ult_v = findPar(v);
            if(ult_u == ult_v) return;
            if(rank[ult_u] < rank[ult_v]){
                parent[ult_u] = ult_v;
            }
            else if(rank[ult_v] < rank[ult_u]){
                parent[ult_v] = ult_u;
            }
            else {
                parent[ult_v] = ult_u;
                rank[ult_u]++;
            }
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

int main(){
    DisjointSet ds(7);
    ds.unionBySize(1, 2); 
    ds.unionBySize(2, 3); 
    ds.unionBySize(4, 5); 
    ds.unionBySize(6, 7); 
    ds.unionBySize(5, 6); 
    ds.unionBySize(3, 7); 
    
    if(ds.findPar(3) == ds.findPar(7)){
        cout<<"Same\n";
    }
    else cout<<"Not Same\n";

    ds.unionByRank(1, 2); 
    ds.unionByRank(2, 3); 
    ds.unionByRank(4, 5); 
    ds.unionByRank(6, 7); 
    ds.unionByRank(5, 6); 
    ds.unionByRank(3, 7); 

    
    if(ds.findPar(2) == ds.findPar(5)){
        cout<<"Same\n";
    }
    else cout<<"Not Same\n";

    return 0;
}