class Solution {
public:
    int firstStableIndex(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>p(n);
        p[0]=arr[0];
        for(int i=1;i<n;i++)
            {
                if(arr[i]>p[i-1])
                {
                    p[i]=arr[i];
                }
                else
                {
                    p[i]=p[i-1];
                }
            }

        vector<int>s(n);
        s[n-1]=arr[n-1];

        for(int i=n-2;i>=0;i--)
            {
                if(arr[i]<s[i+1])
                {
                    s[i]=arr[i];
                }
                else
                {
                    s[i]=s[i+1];
                }
            }

        
        for(int i=0;i<n;i++)
            {
                if(p[i]-s[i]<=k)
                {
                    return i;
                }
            }
        return -1;
    }
};