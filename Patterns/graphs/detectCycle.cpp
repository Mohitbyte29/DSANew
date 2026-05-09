#include <bits/stdc++.h>
using namespace std;

//! BFS
class Solution {
    bool detect(int node, vector<vector<int>>& adj, vector<bool>& visited) {

        visited[node] = true;

        queue<pair<int, int>> q;
        q.push({node, -1});

        while(!q.empty()) {

            int first = q.front().first;
            int parent = q.front().second;

            q.pop();

            for(auto neighbour : adj[first]) {

                if(!visited[neighbour]) {

                    visited[neighbour] = true;

                    q.push({neighbour, first});
                }
                else if(neighbour != parent) {

                    return true;
                }
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

        // Check all components
        for(int i = 0; i < V; i++) {

            if(!visited[i]) {

                if(detect(i, adj, visited))
                    return true;
            }
        }

        return false;
    }
};

