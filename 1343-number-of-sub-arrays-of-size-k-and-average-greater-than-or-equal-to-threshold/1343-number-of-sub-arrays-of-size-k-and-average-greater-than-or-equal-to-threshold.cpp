class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        int n=arr.size();
        int cnt=0;
        int i=0,j=0;
        int sum=0;
        while(j<n)
        {
            sum+=arr[j];
            
            if(j-i+1==k && sum/k>=t)
            {
                cnt++;
            }

            if(j-i+1>k)
            {
                while(j-i+1>k)
                {
                    sum-=arr[i];
                    i++;
                }

                if(j-i+1==k && sum/k>=t)
                {
                    cnt++;
                }
            }

            j++;
        }
        return cnt;
    }
};