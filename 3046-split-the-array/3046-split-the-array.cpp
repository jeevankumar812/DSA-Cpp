class Solution {
public:
    bool isPossibleToSplit(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mpp;
        for(int x:arr)
        {
            mpp[x]++;
        }

        for(auto &it:mpp)
        {
            if(it.second>2)
            {
                return false;
            }
        }
        return true;
    }
};