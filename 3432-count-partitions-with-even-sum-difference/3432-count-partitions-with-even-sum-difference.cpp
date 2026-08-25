class Solution {
public:
    int countPartitions(vector<int>& arr) {
        int cnt=0;
        int n=arr.size();
        int tot_sum=0;
        for(int i=0;i<n;i++)
        {
            tot_sum+=arr[i];
        }

        int left_sum=0;
        for(int i=0;i<n-1;i++)
        {
            left_sum+=arr[i];

            int right_sum=tot_sum-left_sum;

            if(abs(left_sum-right_sum)%2==0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};