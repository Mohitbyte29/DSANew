#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfscheck(int node, vector<vector<int>>& adj,
                  vector<int>& vis,
                  vector<int>& pathvis,
                  vector<int>& check) {

        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;

        for(auto it : adj[node]) {

            // If node is not visited
            if(!vis[it]) {

                if(dfscheck(it, adj, vis, pathvis, check)) {
                    check[node] = 0;
                    return true;
                }
            }

            // If node is already in current DFS path
            else if(pathvis[it]) {
                check[node] = 0;
                return true;
            }
        }

        // Node is safe
        check[node] = 1;
        pathvis[node] = 0;

        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {

        int n = adj.size();

        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> check(n, 0);

        vector<int> safenodes;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfscheck(i, adj, vis, pathvis, check);
            }
        }

        for(int i = 0; i < n; i++) {
            if(check[i] == 1) {
                safenodes.push_back(i);
            }
        }

        return safenodes;
    }
};