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

//* BFS
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> safenodes;
        vector<int> indegree(n, 0);
        queue<int> q;
        vector<vector<int>> adjRev(n);
        for(int i = 0; i<n; i++){
            for(auto it : adj[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safenodes.push_back(node);
            for(auto it:adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(safenodes.begin(), safenodes.end());
        return safenodes;
    };
};