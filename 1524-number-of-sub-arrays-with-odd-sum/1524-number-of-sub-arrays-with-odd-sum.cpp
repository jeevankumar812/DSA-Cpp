class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        long long c = 0;
        int mod = 1e9 + 7;

        int sum = 0;

        int even = 1;
        int odd = 0;

        for(int i = 0; i < n; i++)
        {
            sum += arr[i];

            int curr = sum % 2;

            if(curr == 0)
            {
                c += odd;
                even++;
            }
            else
            {
                c += even;
                odd++;
            }

            c %= mod;
        }

        return c;
    }
};