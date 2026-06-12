//* DFS
class Solution {
    bool dfscheck(int node, vector<int>& vis, vector<int>& pathvis, vector<int>& check,vector<vector<int>>& adj){
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfscheck(it, vis, pathvis, check, adj)){
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathvis[it]){
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> safenodes;
        vector<int> check(n, 0);
        for(auto i = 0; i<n; i++){
            if(!vis[i]){
                dfscheck(i, vis, pathvis, check, adj);
            }
        }
        for(int i = 0; i<n; i++){
            if(check[i] == 1) safenodes.push_back(i);
        }
        return safenodes;
    };
};