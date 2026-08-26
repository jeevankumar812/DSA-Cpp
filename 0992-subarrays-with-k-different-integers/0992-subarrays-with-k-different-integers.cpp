class Solution {
public:

    int atMost(vector<int>&arr,int k)
    {
        unordered_map<int,int>mpp;
        int i=0,j=0;
        int cnt=0;
        int n=arr.size();
        while(j<n)
        {
            mpp[arr[j]]++;

            if(mpp.size()>k)
            {
                while(mpp.size()>k)
                {
                    mpp[arr[i]]--;
                    if(mpp[arr[i]]==0)
                    {
                        mpp.erase(arr[i]);
                    }
                    i++;
                }
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& arr, int k) {
        return atMost(arr,k)-atMost(arr,k-1);
    }
};