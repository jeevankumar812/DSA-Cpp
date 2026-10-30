class Solution {
public:

    int solve(vector<int>&b, int strt, int end)
    {
        int n=end-strt+1;
        if(n==1)
        return b[strt];
        vector<int>dp(n+1);
        dp[0]=b[strt];
        dp[1]=max(b[strt],b[strt+1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max({b[strt+i]+dp[i-2],dp[i-1]});
        }

        return dp[n-1];
    }

    int rob(vector<int>& b) {
        int n=b.size();
        if(n==0)
        return 0;

         if(n == 1) return b[0];

        int first=solve(b,0,n-2);
        int second=solve(b,1,n-1);
        return max(first,second);
    }
};