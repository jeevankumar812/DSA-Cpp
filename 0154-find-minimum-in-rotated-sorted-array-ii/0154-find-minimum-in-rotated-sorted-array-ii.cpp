class Solution {
public:
    int findMin(vector<int>& b) {
        sort(b.begin(),b.end());
        if(b.size()==0)
        return -1;

        return b[0];
    }
};