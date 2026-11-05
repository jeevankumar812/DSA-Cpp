class Solution {
public:
    int findTheDistanceValue(vector<int>& b1, vector<int>& b2, int d) {
        int n=b1.size();
        int m=b2.size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            int val=b1[i];

            for(int j=0;j<m;j++)
            {
                if(abs(val-b2[j])<=d)
                {
                    c++;
                    break;
                }
            }
        }
        return n-c;
    }
};