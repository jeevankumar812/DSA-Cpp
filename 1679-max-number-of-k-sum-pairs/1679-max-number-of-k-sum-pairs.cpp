class Solution {
public:
    int maxOperations(vector<int>& arr, int k) {
        unordered_map<int,int>mpp;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            mpp[arr[i]]++;
        }
        
        int cnt=0;

        for(int i=0;i<n;i++)
        {
            if(mpp.find(arr[i])!=mpp.end())
            {
                mpp[arr[i]]--;

                if(mpp[arr[i]]==0)
                {
                    mpp.erase(arr[i]);
                }

                int need=k-arr[i];
                if(mpp.find(need)!=mpp.end())
                {
                    cnt++;
                    mpp[need]--;
                    if(mpp[need]==0)
                    {
                        mpp.erase(need);
                    }
                }
            }
        }
        return cnt;
    }
};