class Solution {
public:
    int minMoves(vector<int>& b) {
        int d=*min_element(b.begin(),b.end());
        int n=b.size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            c+=b[i]-d;
        }
        return c;
    }
};