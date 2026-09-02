class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        int cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]!=val)
            arr[cnt++]=arr[i];
        }
        return cnt;
    }
};