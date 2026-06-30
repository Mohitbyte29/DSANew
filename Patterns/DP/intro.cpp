#include <iostream>
#include <vector>
using namespace std;

//* Without DP
int fabo2(int n){
    if(n <= 1) return n;
    return fabo2(n - 2) + fabo2(n - 1);
}

//* With DP
int fabo(int n, vector<int> &dp){
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fabo(n - 1, dp) + fabo(n - 2, dp);
}

int main(){
    int num;
    cin >> num;
    vector<int> dp(num + 1, -1); 
    cout << fabo(num, dp)<<endl;
    cout << fabo2(num);
    // cout<<ans;
    return 0;
}

