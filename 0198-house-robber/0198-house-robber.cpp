class Solution {
public:
    int rob(vector<int>& b) {
        int n=b.size();
        if(n==0)
        return 0;

        if(n==1)
        return b[0];


        vector<int>dp(n+1);
        dp[0]=b[0];
        dp[1]=max(b[0],b[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max({b[i]+dp[i-2],dp[i-1]});
        }

        return dp[n-1];
    }
};