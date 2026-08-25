class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {  
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=arr[j];
                if((j-i+1)%2!=0)
                {
                    cnt+=sum;
                }
            }
        }
        return cnt;
    }
};