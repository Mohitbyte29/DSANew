class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        for(auto &i : edges){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        pq.push({0, 0});
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum += wt;
            for(auto iter: adj[node]){
                int adjNode = iter.first;
                int edjW = iter.second;
                if(!vis[adjNode]){
                    pq.push({edjW, adjNode});
                }
            }
        }
        return sum;
    }
};