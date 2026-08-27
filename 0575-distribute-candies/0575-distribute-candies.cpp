class Solution {
public:
    int distributeCandies(vector<int>& arr) {
        unordered_set<int>s;
        for(auto x:arr)
        {
            s.insert(x);
        }

       return min((int)s.size(), (int)arr.size()/2);
    }
};