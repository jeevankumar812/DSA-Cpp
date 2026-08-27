class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            int j=i+1;
            int inc=0,dec=0;
            while(j<n && arr[j] >arr[j-1])
            {
                inc=1;
                j++;
            }

            while(j<n && arr[j]<arr[j-1])
            {
                dec=1;
                j++;
            }

            if(inc && dec)
            {
                ans=max(ans,j-i);
                inc=0,dec=0;
            }
        }

        return ans;
    }
};