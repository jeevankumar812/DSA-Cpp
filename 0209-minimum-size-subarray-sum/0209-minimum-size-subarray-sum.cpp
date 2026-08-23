class Solution {
public:
    int minSubArrayLen(int k, vector<int>& arr) {
        int n=arr.size();


        vector<int>p(n+1,0);
        p[0]=0;
        for(int i=1;i<=n;i++)
        {
            p[i]=p[i-1]+arr[i-1];
        }
        int len=INT_MAX;

        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[p[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            int tar=k+p[i];

            int j = lower_bound(p.begin() + i + 1, p.end(), tar) - p.begin();
            if(j<=n)
            {
                len=min(len,j-i);
            }
            
        }
        return len==INT_MAX?0:len;
    }
};