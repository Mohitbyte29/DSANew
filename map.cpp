#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    // pre-compute
    map<int, int> mpp;
    for(int i = 0; i<n; i++){
        mpp[arr[i]]++;
    }

    // iterate in the map

    for(auto it : mpp){
        cout << it.first << " -> " << it.second << endl;
    }

    int p;
    cin>>p;
    
    while (p--)
    {
        int number;
        cin>>number;
        cout<<mpp[number]<<endl;
    }
    
    return 0;
}