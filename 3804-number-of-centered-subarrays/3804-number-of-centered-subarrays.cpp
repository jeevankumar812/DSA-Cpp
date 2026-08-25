class Solution {
public:


    int centeredSubarrays(vector<int>& arr) {
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            unordered_set<int>s;
            for(int j=i;j<n;j++)
            {
                sum+=arr[j];
                s.insert(arr[j]);
                if(s.find(sum)!=s.end())
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};