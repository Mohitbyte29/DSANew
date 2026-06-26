
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int, int>> adj[n + 1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);
        vector<int> parent(n + 1);
        for(int i = 0; i<=n; i++) parent[i] = i;
        dist[1] = 0;
        pq.push({0, 1});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (dis > dist[node]) continue;  
            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjWt = it.second;
                if(dis + adjWt < dist[adjNode]){
                    dist[adjNode] = dis + adjWt;
                    pq.push({dis + adjWt, adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        if(dist[n] == 1e9) return {-1};
        vector<int> path;
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        path.insert(path.begin(), dist[n]);
        return path;
    }
};