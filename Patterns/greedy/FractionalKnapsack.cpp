#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    static bool comp(pair<int,int>& a, pair<int,int>& b) {
        double r1 = (double)a.first / a.second;
        double r2 = (double)b.first / b.second;
        return r1 > r2;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();

        vector<pair<int,int>> items(n);
        for (int i = 0; i < n; i++)
            items[i] = {val[i], wt[i]};

        sort(items.begin(), items.end(), comp);

        double totalValue = 0.0;
        int remaining = capacity;

        for (int i = 0; i < n; i++) {
            if (remaining == 0) break;

            int v = items[i].first;
            int w = items[i].second;

            if (w <= remaining) {
                totalValue += v;
                remaining -= w;
            } else {
                totalValue += (double)v * remaining / w;
                remaining = 0;
            }
        }

        return totalValue;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, capacity;
        cin >> n >> capacity;

        vector<int> val(n), wt(n);
        for (int i = 0; i < n; i++) cin >> val[i];
        for (int i = 0; i < n; i++) cin >> wt[i];

        Solution obj;
        cout << fixed << setprecision(6) << obj.fractionalKnapsack(val, wt, capacity) << "\n";
    }
    return 0;
}