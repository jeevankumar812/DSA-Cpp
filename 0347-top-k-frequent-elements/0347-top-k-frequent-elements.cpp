class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }

        vector<pair<int,int>>vec;
        for(auto it:mpp)
        {
            vec.push_back({it.first,it.second});
        }

        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(vec[i].first);
        }
        return ans;

    }
};