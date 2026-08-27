class Solution {
public:
    int findPairs(vector<int>& arr, int k) {
        int n=arr.size();
        int cnt=0;

        map<vector<int>, int> mpp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                continue;

                if(abs(arr[i]-arr[j])==k)
                {
                    vector<int>vec;
                    vec.push_back(arr[i]);
                    vec.push_back(arr[j]);
                    sort(vec.begin(),vec.end());
                    mpp[vec]++;
                }
            }
        }
        return mpp.size();
    }
};