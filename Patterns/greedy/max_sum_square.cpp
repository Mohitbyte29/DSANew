//* Brute Approach
#include <iostream>
using namespace std;


class Solution {
    long long check(int num, int sum, int res, int ans){
        if(num == 0){
            return res == sum ? ans : -1;
        }
        long long first = num % 10;
        long long second = num / 10;
        res += first;
        ans += first*first;
        return check(second, sum, res, ans);
    }
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";
        string maxNum = "";
        for(int i = 0; i < num; i++){
            maxNum += '9';
        }
        long long high = stoi(maxNum);
        long long low = 1;
        for(int i = 1; i < num; i++) low *= 10;
        long long bestAns = -1, bestNum = -1;
        for(int i = low; i <= high; i++){
            long long ans = check(i, sum, 0, 0);
            if (ans >= bestAns && ans != -1) {  
                bestAns = ans;
                bestNum = i;
            }
        }
        return bestNum == -1 ? "" : to_string(bestNum);
    }
};

//* optimum
string res(num, '0');
        for (int i = 0; i < num && sum > 0; i++) {
            int d = min(9, sum);
            res[i] = '0' + d;
            sum -= d;
        }
        return res;
