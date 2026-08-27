class Solution {
public:
    int numIdenticalPairs(vector<int>& arr
    ) {
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j ||i>j)
                {
                    continue;
                }

                if(arr[i]==arr[j])
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};