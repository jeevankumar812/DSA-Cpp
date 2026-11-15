class Solution {
public:
    int numOfSubarrays(vector<int>& b) {
        int n=b.size();
        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        const int MOD = 1e9 + 7;
        if(b[0]%2==0)
        {
            dp[0][0]=1;
        }
        else
        {
            dp[0][1]=1;
        }

        for(int i=1;i<n;i++)
        {
            if(b[i]%2==0)
            {
                dp[i][0]=(1+dp[i-1][0])%MOD;
                dp[i][1]=dp[i-1][1];
            }
            else
            {
                dp[i][0]=dp[i-1][1];
                dp[i][1]=(1+dp[i-1][0])%MOD;
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans=(ans + dp[i][1])%MOD;
        }

        return ans;
    }
};