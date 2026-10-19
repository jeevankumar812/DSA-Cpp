class Solution {
public:

    int firstOccurences(vector<int>&b, int k)
    {
        int ans=-1;
        int low=0,high=b.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(b[mid]==k)
            {
                ans=mid;
                high=mid-1;
            }
            else if(b[mid]<k)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }


    int secondOccurences(vector<int>&b, int k)
    {
        int low=0,high=b.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(b[mid]==k)
            {
                ans=mid;
                low=mid+1;
            }
            else if(b[mid]<k)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }

    vector<int> targetIndices(vector<int>& b, int k) {
        sort(b.begin(),b.end());
        int first=firstOccurences(b,k);
        int second=secondOccurences(b,k);

        vector<int>ans;
        if(first==-1 || second==-1)
        return ans;


        
        for(int i=first;i<=second;i++)
        {
            ans.push_back(i);
        }
        return ans;

    }
};