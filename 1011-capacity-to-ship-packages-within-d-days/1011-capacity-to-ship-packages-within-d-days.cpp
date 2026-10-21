class Solution {
public:
    bool check(vector<int>& weights, int days, int capacity) {
        int day = 1;
        int sum = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] <= capacity) {
                sum += weights[i];
            } else {
                day++;
                sum = weights[i];
            }
        }

        return day <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};