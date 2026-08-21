class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {

        int n=arr.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            if(mpp.find(arr[i])!=mpp.end())
            {
                int prev=mpp[arr[i]];
                if(i-prev<=k)
                {
                    return true;
                }
                
            }
            mpp[arr[i]]=i;
        }
        return false;
    }
};