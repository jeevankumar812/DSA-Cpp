class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,int>mpp;
        for(auto e:edges)
        {
            int u=e[1];
            mpp[u]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(mpp.find(i)!=mpp.end())
            {
                continue;
            }
            else
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};