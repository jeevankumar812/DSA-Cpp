class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int i=0,j=0;
        int n=arr.size();
        int ans=INT_MIN;
        int sum=0;
    
        unordered_map<int,int>mpp;
        while(j<n)
        {
            mpp[arr[j]]++;
            sum+=arr[j];
            if(mpp.size()>2)
            {
                while(mpp.size()>2)
                {
                    sum-=arr[i];
                    mpp[arr[i]]--;
                    if(mpp[arr[i]]==0)
                    {
                        mpp.erase(arr[i]);
                    }
                    i++;
                }
            }

            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};