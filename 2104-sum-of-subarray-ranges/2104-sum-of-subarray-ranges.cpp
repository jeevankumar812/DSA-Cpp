class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        long long ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            int maxi=INT_MIN;
            int mini=INT_MAX;
            for(int j=i;j<n;j++)
            {
                maxi=max(maxi,arr[j]);
                mini=min(mini,arr[j]);

                int val=maxi-mini;
                ans+=(long long)val;
            }
        }
        return ans;
    }
};