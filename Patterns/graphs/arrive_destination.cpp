class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        vector<pair<int, int>> adj[V];
        for(auto it:edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9), ways(V, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode = it.first;
                int adjW = it.second;
                if(dis + adjW < dist[adjNode]){
                    dist[adjNode] = dis + adjW;
                    pq.push({dis + adjW, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis + adjW == dist[adjNode]){
                    ways[adjNode] = ways[adjNode] + ways[node];
                }
            }
        }
        return ways[V - 1];
    }
};