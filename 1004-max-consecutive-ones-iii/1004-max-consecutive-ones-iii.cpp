class Solution {
public:
    int longestOnes(vector<int>& b, int k) {
        
        int i=0,j=0;
        int n=b.size();
        int res=0;
        int zero=0;
        while(j<n)
        {
            if(b[j]==0)
            {
                zero++;
            }

            while(zero>k)
            {
                if(b[i]==0)
                {
                    zero--;
                }
                i++;
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};