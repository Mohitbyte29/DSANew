#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>> &adj, int n){
    vector<bool> vis(n, false);
    queue<int> q;

    vis[start] = true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        if(!vis[node]){
            cout<<node<<" ";
            vis[node] = true;
        }

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = true;
                q.push(it);
            }
        }
    }
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5};
    adj[3] = {1};
    adj[4] = {1};
    adj[5] = {2};

    bfs(0, adj, n);              
    return 0;
}