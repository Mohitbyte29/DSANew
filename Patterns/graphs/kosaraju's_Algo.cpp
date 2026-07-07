class Solution {
    void dfs(int i, vector<vector<int>> &adj, vector<int>& vis, stack<int>& st){
        vis[i] = 1;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it, adj, vis, st);
            }
        }
        st.push(i);
    }
    void dfs3(int i, vector<vector<int>> &adjT, vector<int>& vis){
        vis[i] = 1;
        for(auto it:adjT[i]){
            if(!vis[it]){
                dfs3(it, adjT, vis);
            }
        }
    }
  public:
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
         vector<vector<int>> adj(V);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        //! Sort All the edges according to the finish time of the nodes
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }

        //! Reverse the graph
        vector<vector<int>> adjT(V);
        for(int i = 0; i<V; i++){
            vis[i] = 0;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }

        //! pop the nodes from the stack and do dfs on the reversed graph
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs3(node, adjT, vis);
            }
        }
        return scc;
    }
};