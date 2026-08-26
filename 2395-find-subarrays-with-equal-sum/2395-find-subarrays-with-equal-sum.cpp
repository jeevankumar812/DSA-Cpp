class Solution {
public:
    bool findSubarrays(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int>s;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=(long long)arr[j];
                if(s.find(sum)!=s.end() && j-i+1==2)
                {
                    return true;
                }
                
                if(s.find(sum)==s.end()&& j-i+1==2)
                {
                    s.insert(sum);
                }   
            }
        }
        return false;
    }
};