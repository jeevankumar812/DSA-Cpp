class Solution {
public:
    int maxSubArray(vector<int>& b) {
        
        int n=b.size();

        if(n==0)
        return 0;

        if(n==1)
        return b[0];
        vector<int>dp(n+1);
        dp[0]=b[0];
        int ans=dp[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=max(b[i],b[i]+dp[i-1]);
            ans=max(ans,dp[i]);
        }

        return ans;
    }
};