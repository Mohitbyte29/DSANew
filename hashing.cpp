#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    // pre-compute
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    int hashh[100000] = {0};
    for(int i = 0; i<n; i++){
        hashh[arr[i]] += 1; 
    }

    int p;
    cin>>p;
    while(p--){
        int number;
        cin >> number;
        // fetch
        cout<<hashh[number]<<endl;
    }
    return 0;
}