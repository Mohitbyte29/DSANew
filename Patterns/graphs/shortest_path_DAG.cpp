class Solution {
	void topoSort(int node, vector<pair<int, int>> adj[], vector<int>& vis, stack<int>& st) {
		vis[node] = 1;
		for (auto it:adj[node]) {
			int v = it.first;
			if (!vis[v]) {
				topoSort(v, adj, vis, st);
			}
		}
		st.push(node);
	}
	public:
	vector<int> shortestPath(int V, int E, vector<vector<int>> & edges) {
		// code here
		vector<pair<int, int>> adj[V];
		for (int i = 0; i<E; i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			int wt = edges[i][2];
			adj[u].push_back({v, wt});
		}
		vector<int> vis(V, 0);
		stack<int> st;
		for (int i = 0; i<V; i++) {
			if (!vis[i]) {
				topoSort(i, adj, vis, st);
			}
		}
		
		vector<int> dist(V);
		for (int i = 0; i<V; i++) {
			dist[i] = INT_MAX;
		}
		dist[0] = 0;
		while (!st.empty()) {
			int node = st.top();
			st.pop();
			if (dist[node] != INT_MAX) {
				for (auto it:adj[node]) {
					int u = it.first;
					int wt = it.second;
					
					if (dist[node] + wt < dist[u]) {
						dist[u] = dist[node] + wt;
					}
				}
			}
		}
		for (int i = 0; i<V; i++) {
			if (dist[i] == INT_MAX)
				dist[i] = -1;
		}
		
		return dist;
	}
};
