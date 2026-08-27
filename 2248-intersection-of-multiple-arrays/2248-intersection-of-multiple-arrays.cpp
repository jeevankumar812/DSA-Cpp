class Solution {
public:
    vector<int> intersection(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<arr[i].size();j++)
            {
                mpp[arr[i][j]]++;
            }
        }
        vector<int>ans;
        for(auto it:mpp)
        {
            if(it.second==n)
            {
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};