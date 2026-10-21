class Solution {
public:

    bool check(int d, vector<int>&b, int n, int k)
    {
        int t=0;
        for(int i=0;i<n;i++)
        {
            if(b[i]<d)
            {
                t=t+1;
            }
            else
            {
                if(b[i]%d==0)
                {
                    t=t+b[i]/d;
                }
                else
                {
                    t=t+(b[i]/d)+1;
                }
            }
        }

        if(t<=k)
        {
            return true;
        }

        return false;
    }

    int smallestDivisor(vector<int>& b, int k) {
        int n=b.size();
        int i=1;
        int maxi=*max_element(b.begin(),b.end());
        int low=1,high=maxi;
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(check(mid,b,n,k)==true)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }

        }
        return ans;
    }
};