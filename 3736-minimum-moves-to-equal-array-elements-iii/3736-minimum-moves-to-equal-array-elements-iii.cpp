class Solution {
public:
    int minMoves(vector<int>& b) {
        int d=*max_element(b.begin(),b.end());
        int n=b.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int c=d-b[i];
            ans+=c;
        }
        return ans;
    }
};