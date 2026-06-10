class Solution {
    bool dfscheck(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathvis){
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfscheck(it, adj, vis, pathvis)){
                    return true;
                }
            }
            else if(pathvis[it]){
                return true;
            }
        }
        pathvis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(V);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(dfscheck(i, adj, vis, pathvis)){
                    return false;
                }
            }
        }
        return true;
    }
};