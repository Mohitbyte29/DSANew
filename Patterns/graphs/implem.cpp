#include <iostream>
#include <vector>
using namespace std;


int main(){
    int V = 6;
    vector<vector<int>> adj(V + 1);
    adj[1].push_back(4);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[3].push_back(2);
    adj[4].push_back(1);
    adj[4].push_back(2);
    adj[4].push_back(6);
    adj[5].push_back(2);
    adj[6].push_back(4);

    for(int i = 1; i < V + 1; i++){
        cout<< i << " -> ";
        for(int neighbour : adj[i]){
            cout<<neighbour<<' ';
        }
        cout<<endl;
    }

}