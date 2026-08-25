class Solution {
public:

    long long maxSum(vector<int>& arr, int m, int k) {
        long long sum=0;
        long long ans=INT_MIN;
        int n=arr.size();
        int i=0,j=0;
        unordered_map<int,int>mpp;
        while(j<n)
        {
            sum+=arr[j];
            mpp[arr[j]]++;

            if(j-i+1==k && mpp.size()>=m)
            {
                ans=max(ans,sum);
            }

            if(j-i+1>k)
            {
                while(j-i+1>k)
                {
                    sum-=arr[i];
                    mpp[arr[i]]--;
                    if(mpp[arr[i]]==0)
                    {
                        mpp.erase(arr[i]);
                    }
                    i++;
                }

                if(j-i+1==k && mpp.size()>=m)
                {
                    ans=max(ans,sum);
                }
            }

            j++;
        }
        return ans==INT_MIN?0:ans;
    }
};