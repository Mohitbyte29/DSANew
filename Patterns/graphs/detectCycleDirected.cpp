//* BFS Approach

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &adj) {
        // code here
        vector<vector<int>> edges(V);
        for(auto &edge : adj){
            edges[edge[0]].push_back(edge[1]);
        }
          vector<int> indegree(V, 0);
        for(int i = 0; i<V; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(auto i = 0; i<V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        int cnt = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it : edges[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(cnt == V) return false;
        return true;
    }
};