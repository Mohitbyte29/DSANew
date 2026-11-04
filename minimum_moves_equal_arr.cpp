class Solution {
public:
    int minMoves2(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        int target = a[n / 2];
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += abs((long long)a[i] - target);
        }
        return cnt;

    }
    }
};