
class Solution {
public:
    long long maxSubarraySum(vector<int>& b, int k) {
        int n = b.size();

        vector<long long> pre(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + b[i];
        }

        long long res = LLONG_MIN;
        vector<long long> mini(k, LLONG_MAX);

        for (int i = 0; i <= n; i++) {
            int rem = i % k;

            if (mini[rem] != LLONG_MAX) {
                res = max(res, pre[i] - mini[rem]);
            }

            mini[rem] = min(mini[rem], pre[i]);
        }

        return res;
    }
};
