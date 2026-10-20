#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string a, string b) {
        if (a == "0" || b == "0") return "0";

        int n1 = a.size(), n2 = b.size();
        vector<int> result(n1 + n2, 0);
        for(int i = n1 - 1; i >= 0; i--){
            for(int j = n2 - 1; j >= 0; j--){
                int mul = (a[i] - '0') * (b[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + result[p2];
                result[p2] = sum % 10;
                result[p1] += sum / 10;
            }
        }
        string ans;
        for(int digit : result){
            if(!(ans.empty() && digit == 0)){
                ans += to_string(digit);
            }
        }
        return ans;
    }
};