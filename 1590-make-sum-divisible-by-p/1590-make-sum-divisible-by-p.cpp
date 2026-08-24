class Solution {
public:
    int minSubarray(vector<int>& arr, int p) {
        int n=arr.size();
        int ans=INT_MAX;

        long long tar=0;
        for(int x:arr)
        {
            tar+=x;
        }

        int target = tar % p;
        if(target == 0)
            return 0;

        unordered_map<int,int>mpp;
        long long sum=0;
        mpp[0]=-1;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            int rem=sum%p;
            int need=(rem-target+p)%p;
            if(mpp.find(need)!=mpp.end())
            {
                ans = min(ans, i - mpp[need]);
            }

            mpp[rem]=i;
        }
        return ans==INT_MAX||ans == n?-1 :ans;
    }
};