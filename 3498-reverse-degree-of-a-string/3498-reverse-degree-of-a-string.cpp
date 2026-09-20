class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char,int>mpp;
        int num=26;
        for(char ch='a';ch<='z';ch++)
        {
            mpp[ch]=num;
            num--;
        }
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int val=i+1;
            int prod=val*mpp[s[i]];
            sum+=prod;
        }
        return sum;
    }
};