class Solution {
public:
    int missingMultiple(vector<int>& arr, int k) {
        unordered_set<int>s;
        for(int x:arr)
        {
            s.insert(x);
        }
        int i=k;
        while(s.find(i)!=s.end())
        {
            i=i+k;
        }

        return i;

    }
};