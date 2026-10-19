class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& b) {
        vector<int>arr=b;
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mpp;
        int rank=1;
        for(int i=0;i<arr.size();i++)
        {
            if(mpp.find(arr[i])==mpp.end())
            {
                mpp[arr[i]]=rank;
                rank++;
            }
        }
        vector<int>ans;
        for(int i=0;i<b.size();i++)
        {
            ans.push_back(mpp[b[i]]);
        }
        return ans;
    }
};