#include <bits/stdc++.h>
using namespace std;

void dfsHelper(int node, vector<vector<int>> &adj, 
               vector<int> &visited, vector<int> &dfs) {
    
    visited[node] = 1;
    dfs.push_back(node);

    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfsHelper(neighbour, adj, visited, dfs);
        }
    }
}

vector<int> dfs(vector<vector<int>> &adj) {
    int V = adj.size();
    vector<int> visited(V, 0);
    vector<int> result;

    dfsHelper(0, adj, visited, result);  // start from node 0
    return result;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    // Example graph
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5};
    adj[3] = {1};
    adj[4] = {1};
    adj[5] = {2};

    vector<int> res = dfs(adj);

    for (int node : res) {
        cout << node << " ";
    }

    return 0;
}