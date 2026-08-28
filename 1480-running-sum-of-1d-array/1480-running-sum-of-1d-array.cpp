class Solution {
public:
    vector<int> runningSum(vector<int>& arr) {
        int n=arr.size();
        vector<int>p(n);
        p[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            p[i]=p[i-1]+arr[i];
        }
        return p;
    }
};