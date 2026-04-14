#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        
        // Step 1: sort both arrays in descending order
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        // max heap -> {sum, {i, j}}
        priority_queue<pair<int, pair<int, int>>> pq;
        
        // to avoid duplicate pairs
        set<pair<int, int>> visited;

        // initial push
        pq.push({a[0] + b[0], {0, 0}});
        visited.insert({0, 0});

        vector<int> ans;

        // get top k sums
        while(k--) {
            auto top = pq.top();
            pq.pop();

            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;

            ans.push_back(sum);

            // next pair (i+1, j)
            if(i + 1 < n && !visited.count({i + 1, j})) {
                pq.push({a[i + 1] + b[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

            // next pair (i, j+1)
            if(j + 1 < n && !visited.count({i, j + 1})) {
                pq.push({a[i] + b[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }

        return ans;
    }
};