class Solution {
public:
    vector<int> leftRightDifference(vector<int>& arr) {
        int n=arr.size();
        vector<int>p(n);
        p[0]=0;
        for(int i=0;i<n-1;i++)
        {
            p[i+1]=arr[i]+p[i];
        }

        vector<int>s(n);
        s[n-1]=0;
        for(int i=n-1;i>=1;i--)
        {
            s[i-1]=arr[i]+s[i];
        }

        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=abs(p[i]-s[i]);
        }
        return ans;
    }
};