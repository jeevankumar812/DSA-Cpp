class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        int passenger[1001] = {0};

        for (int i = 0; i < trips.size(); i++) {

            int num = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];

            for (int j = from; j < to; j++) {

                passenger[j] += num;

                if (passenger[j] > capacity)
                    return false;
            }
        }

        return true;
    }
};