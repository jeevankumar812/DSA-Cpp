class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector<int>p(n,0);
        for(int i=0;i<bookings.size();i++)
        {
            int strt=bookings[i][0];
            int end=bookings[i][1];
            int val=bookings[i][2];

            for(int j=strt;j<=end;j++)
            {
                p[j-1]=p[j-1]+val;
            }
        }
        return p;
    }
};