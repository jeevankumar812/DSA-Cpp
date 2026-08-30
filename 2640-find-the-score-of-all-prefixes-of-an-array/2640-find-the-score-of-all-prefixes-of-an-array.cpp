class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& arr) {
        int n=arr.size();
        vector<long long>p(n);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i]);
            p[i]=arr[i]+maxi;
        }
        
        vector<long long>prefix(n);
        prefix[0]=p[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+p[i];
        }
        return prefix;
    }
};