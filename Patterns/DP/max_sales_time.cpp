
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // Cheapest item price
        int cheapest = INT_MAX;

        // freeCnt[i] = number of free items received
        // when buying the first copy of item i
        vector<int> freeCnt(n, 0);

        for (int i = 0; i < n; i++) {
            cheapest = min(cheapest, items[i][1]);

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeCnt[i]++;
                }
            }
        }

        // 0/1 Knapsack
        // dp[j] = maximum items obtainable by selecting
        // distinct item types with total cost at most j
        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int price = items[i][1];

            // Reverse iteration ensures each item type
            // contributes its free items at most once
            for (int j = budget; j >= price; j--) {
                dp[j] = max(
                    dp[j],
                    dp[j - price] + freeCnt[i] + 1
                );
            }
        }

        int ans = 0;

        // Spend the remaining budget on the cheapest item
        for (int j = 0; j <= budget; j++) {
            int total = dp[j] + (budget - j) / cheapest;
            ans = max(ans, total);
        }

        return ans;
    }
};
