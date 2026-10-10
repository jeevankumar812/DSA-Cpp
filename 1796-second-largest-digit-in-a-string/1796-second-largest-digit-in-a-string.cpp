class Solution {
public:
    int secondHighest(string s) {

        unordered_set<int>st;
        vector<int>ans;
       

        for(int i=0;i<s.size();i++)
        {
            if(isdigit(s[i]))
            {
                int num=s[i]-'0';
                if(st.find(num)==st.end())
                {
                    ans.push_back(num);
                    st.insert(num);
                }
                
            }
        }

        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());

        if(ans.size() < 2)
        return -1;

        return ans[1];
    }
};