//* BFS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    bool check(int start, int size, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;

        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : graph[node]) {
                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (check(i, n, graph, color) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    if (obj.isBipartite(graph))
        cout << "Graph is Bipartite";
    else
        cout << "Graph is Not Bipartite";

    return 0;
}