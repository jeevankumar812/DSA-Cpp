class Solution {
public:
    int arrangeCoins(int n) {
        int s=n;
        int i=1;
        if(n==1)
        {
            return 1;
        }

        if(n==3)
        {
            return 2;
        }
        while(s>0)
        {
            s-=i;
            if(s==0)
            {
                return i;
            }
            i++;
        }
        return i-2;
    }
};