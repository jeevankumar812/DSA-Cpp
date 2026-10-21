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
        while(i<=limit)
        {
            if(check(i,b,n))
            {
                ans=i;
            }
            else
            {
                break;
            }
            i++;
        }
        return ans;
    }
};