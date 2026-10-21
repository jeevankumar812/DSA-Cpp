class Solution {
public:

    bool check(int h,vector<int>&b, int n)
    {
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(h>b[i])
            {
                continue;
            }
            else
            {
                c++;
            }
        }

        if(c>=h)
        {
            return true;
        }

        return false;
    }

    int hIndex(vector<int>& b) {
        int n=b.size();
        int i=1;
        int limit=*max_element(b.begin(),b.end());
        int ans=0;
        int low=1,high=limit;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(check(mid,b,n)==true)
            {
                
                if(high==low || check(mid+1,b,n)==false)
                {
                    ans=mid;
                    break;
                }
                else
                {
                    low=mid+1;
                }
            }
            else
            {
                high=mid-1;
            }
            
        }
        return ans;
    }
};