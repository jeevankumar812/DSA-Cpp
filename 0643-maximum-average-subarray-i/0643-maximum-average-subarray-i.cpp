class Solution {
public:
    double findMaxAverage(vector<int>& a, int k) {
        int ans=0;
        int i=0,j=0;
        double res=INT_MIN;
        int n=a.size();
        while(j<n)
        {
            ans+=a[j];

            if(j-i+1==k)
            {
                double val=(double)ans/k;
                res=max(res,val);
                ans-=a[i];
                i++;
            }

            j++;
        }
        return res;
    }
};