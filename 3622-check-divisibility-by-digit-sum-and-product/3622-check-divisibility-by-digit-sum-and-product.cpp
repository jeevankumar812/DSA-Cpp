class Solution {
public:
    int multiply(int n)
    {
        int cnt=1;
        while(n>0)
            {
                int temp=n%10;
                cnt*=temp;
                n=n/10;
            }
        return cnt;
    }
    int sumOf(int n)
    {
        int cnt=0;
        while(n>0)
        {
            int temp=n%10;
            cnt+=temp;
            n=n/10;
        }  
        return cnt;
    }
    bool checkDivisibility(int n) {
        int sum=sumOf(n);
        int mul=multiply(n);
        int cnt=sum+mul;
        return n%cnt==0;
    }
};