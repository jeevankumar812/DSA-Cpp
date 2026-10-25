
class Solution {
public:

    int f(int d, vector<int>&b, int n)
    {
        int sum=0;

        for(int i=0;i<n;i++)
        {
            sum+=min(b[i],d);
        }

        return sum;
    }

    int findBestValue(vector<int>& b, int k) {
        int i=0;
        int limit=*max_element(b.begin(),b.end());

        int res=-1;
        int temp=INT_MAX;
        int n=b.size();

        while(i<=limit)
        {
            int mid=i+(limit-i)/2;
            int check=f(mid,b,n);

            if(abs(check-k)<temp ||
              (abs(check-k)==temp && mid<res))
            {
                temp=abs(check-k);
                res=mid;
            }

            if(check<k)
            {
                i=mid+1;
            }
            else
            {
                limit=mid-1;
            }
        }

        return res;
    }
};
