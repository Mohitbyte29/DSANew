#include <iostream>
#include <map>

using namespace std;

int main(){
    string s;
    map<char, int> mpp;
    cin >> s;

    // pre-compute
    for(char ch : s){
        mpp[ch]++;
    }
    
    // iterate
    for(auto it:mpp){
        cout<< it.first << " --> " << it.second << endl;
    }

    int p;
    cin >> p;
    while(p--){
        char ch;
        cin >> ch;
        cout << ch << " appears " << mpp[ch] << " times\n";
    }

    // fetch
    return 0;
}