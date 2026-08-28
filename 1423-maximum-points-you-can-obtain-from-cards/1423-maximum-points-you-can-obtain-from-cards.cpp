class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>p(n);
        p[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            p[i]=p[i-1]+arr[i];
        }

        vector<int>s(n);
        s[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            s[i]=s[i+1]+arr[i];
        }

        int maxi=INT_MIN;
        int temp=0;
        for(int i=0;i<=k;i++)
        {
           int left=0;
           int right=0;

           if(i>0)
           {
              left=p[i-1];
           }

           if(k-i>0)
           {
                right=s[n-(k-i)];
           }

           maxi=max(maxi,right+left);

        }
        return maxi;
    }   
};