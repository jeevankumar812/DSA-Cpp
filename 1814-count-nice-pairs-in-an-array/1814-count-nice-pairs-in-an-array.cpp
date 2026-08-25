class Solution {
public:
    const int MOD = 1000000007;
    int rev(int n)
    {
        int reverse=0;
        while(n>0)
        {
            int temp=n%10;
            reverse=(reverse*10)+temp;
            n/=10;
        }
        return reverse;
    }

    int countNicePairs(vector<int>& arr) {
        
        long long c=0;
        unordered_map<int, long long> mpp;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            int val=arr[i]-rev(arr[i]);
            c+=mpp[val];
            mpp[val]++;
        }

        return c%MOD;
    }
};