class Solution {
public:
    const int MOD=1000000007;
    int rangeSum(vector<int>& arr, int n, int left, int right) {
        vector<int>vec;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=arr[j];
                vec.push_back(sum);
            }
        }

        sort(vec.begin(),vec.end());
        int j=left-1;
        long long  ans=0;
        while(j<right)
        {
            ans+=vec[j];
            j++;
        }
        return ans%MOD;
    }
};