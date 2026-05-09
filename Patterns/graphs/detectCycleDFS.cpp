#include <bits/stdc++.h>
using namespace std;

//! DFS
class Solution {

    bool dfs(int node, int parent,
             vector<vector<int>>& adj,
             vector<bool>& visited) {

        visited[node] = true;

        for(auto neighbour : adj[node]) {

            if(!visited[neighbour]) {

                if(dfs(neighbour, node, adj, visited))
                    return true;
            }
            else if(neighbour != parent) {

                return true;
            }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        // Create adjacency list
        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);

        // Check all connected components
        for(int i = 0; i < V; i++) {

            if(!visited[i]) {

                if(dfs(i, -1, adj, visited))
                    return true;
            }
        }

        return false;
    }
};