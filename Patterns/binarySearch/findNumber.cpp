class Solution {
public:
    int reachNumber(int target) {

        target = abs(target);

        int low = 0;
        int high = target * 2 + 1;

        // Find minimum steps such that
        // steps * (steps + 1) / 2 >= target

        while (low < high) {

            long long mid = low + (high - low) / 2;

            long long sum = mid * (mid + 1) / 2;

            if (sum >= target) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        int steps = low;

        // Fix parity
        while ((steps * (steps + 1) / 2 - target) % 2 != 0) {
            steps++;
        }

        return steps;
    }
};