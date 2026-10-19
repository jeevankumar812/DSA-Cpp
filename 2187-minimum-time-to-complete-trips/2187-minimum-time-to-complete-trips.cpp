
class Solution {
public:
    long long minimumTime(vector<int>& b, int k) {
        
        int n = b.size();
        long long mini = *min_element(b.begin(), b.end());

        long long low = 1;
        long long high = mini * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long sum = 0;

            for (int j = 0; j < n; j++) {
                sum += mid / b[j];

                if (sum >= k) {
                    break;
                }
            }

            if (sum >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
