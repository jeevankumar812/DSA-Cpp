class Solution {
public:
    int minLength(vector<int>& a, int k) {
        int i=0,j=0;
        int n=a.size();
        int sum=0;
        unordered_map<int,int>mpp;
        int ans=INT_MAX;
        while(j<n)
        {
            if(mpp[a[j]]==0)
            {
                sum+=a[j];
            }
            mpp[a[j]]++;

            while(sum>=k)
            {
                ans=min(ans,j-i+1);
                mpp[a[i]]--;

                if(mpp[a[i]]==0)
                {
                    sum-=a[i];
                }
                i++;
            }
            j++;
        }
        return ans==INT_MAX?-1:ans;

    }
};