#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 5;
    vector<pair<int, int>> adj[n];

    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});
    adj[0].push_back({2, 20});
    adj[2].push_back({0, 20});
    adj[1].push_back({3, 30});
    adj[3].push_back({1, 30});
    adj[2].push_back({4, 40});
    adj[4].push_back({2, 40});

    for(int i = 0; i < n; i++){
        cout << i << " -> ";
        for(auto it : adj[i]){
            cout << "(" << it.first << ", " << it.second << ") ";
        }
        cout << endl;
    }

    return 0;
}