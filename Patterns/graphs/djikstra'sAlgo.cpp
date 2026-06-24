class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int s) {


        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
                vector<int> dist(V, 1e9);
        
        vector<vector<pair<int, int>>> adj(V);
        for(int i = 0; i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int c = edges[i][2];
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }

        for(int i = 0; i<V; i++) dist[i] = 1e9;

        dist[s] = 0;
        pq.push({0, s});

        while(!pq.empty()) {

            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dis>dist[node]){
               continue;
           }

            for(int i = 0; i<adj[node].size() ; i++) {

                int adjNode = adj[node][i].first;
                int adjWt   = adj[node][i].second;
                if(dis + adjWt < dist[adjNode]) {
                    dist[adjNode] = dis + adjWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

By Set
class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int s) {


        set<pair<int,int>> st;
                vector<int> dist(V, 1e9);
        
        vector<vector<pair<int, int>>> adj(V);
        for(int i = 0; i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int c = edges[i][2];
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }

        for(int i = 0; i<V; i++) dist[i] = 1e9;

        dist[s] = 0;
        st.insert({0, s});

        while(!st.empty()) {

            int dis = st.begin()->first;
            int node = st.begin()->second;
            st.erase(st.begin());
            if(dis>dist[node]){
               continue;
           }

            for(int i = 0; i<adj[node].size() ; i++) {

                int adjNode = adj[node][i].first;
                int adjWt   = adj[node][i].second;
                if(dis + adjWt < dist[adjNode]) {
                    dist[adjNode] = dis + adjWt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

By queue(gives TLE)
class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int s) {


        queue<pair<int,int>> pq;
                vector<int> dist(V, 1e9);
        
        vector<vector<pair<int, int>>> adj(V);
        for(int i = 0; i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int c = edges[i][2];
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }

        for(int i = 0; i<V; i++) dist[i] = 1e9;

        dist[s] = 0;
        pq.push({0, s});

        while(!pq.empty()) {

            int dis = pq.front().first;
            int node = pq.front().second;
            pq.pop();
            if(dis>dist[node]){
               continue;
           }

            for(int i = 0; i<adj[node].size(); i++) {

                int adjNode = adj[node][i].first;
                int adjWt   = adj[node][i].second;
                if(dis + adjWt < dist[adjNode]) {
                    dist[adjNode] = dis + adjWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};