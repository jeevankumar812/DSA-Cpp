class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        long long sum=0;
        long long ans=INT_MIN;
        int n=arr.size();
        unordered_map<int,int>mpp;
        int i=0,j=0;
        while(j<n)
        {
            mpp[arr[j]]++;
            sum+=arr[j];
            if(j-i+1==k && mpp[arr[j]]==1)
            {
                ans=max(ans,sum);
            }

            if(mpp[arr[j]]>1)
            {
                while(mpp[arr[j]]>1)
                {
                    mpp[arr[i]]--;
                    sum-=arr[i];
                    if(mpp[arr[i]]==0)
                    {
                        mpp.erase(arr[i]);
                    }
                    i++;
                }
            }

            if(j-i+1>k)
            {
                while(j-i+1>k)
                {
                    mpp[arr[i]]--;
                    sum-=arr[i];
                    if(mpp[arr[i]]==0)
                    {
                        mpp.erase(arr[i]);
                    }
                    i++;
                }

                if(j-i+1==k && mpp[arr[j]]==1)
                {
                    ans=max(ans,sum);
                }
            }

            j++;
        }
        return ans==INT_MIN?0:ans;
    }
};