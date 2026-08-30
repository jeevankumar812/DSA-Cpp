
class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {

        int u = source[0] - 1;
        int v = source[1] - 1;

        int x = target[0] - 1;
        int y = target[1] - 1;

        // Bishop can move in 4 diagonal directions
        int dx[] = {-1, -1, 1, 1};
        int dy[] = {-1, 1, -1, 1};

        int n = 8, m = 8;

        vector<vector<int>> dis(n, vector<int>(m, -1));

        queue<pair<int, int>> q;

        // Source has distance 0
        dis[u][v] = 0;
        q.push({u, v});

        while (!q.empty()) {

            auto curr = q.front();
            q.pop();

            int a = curr.first;
            int b = curr.second;   // FIXED

            // If we reached target
            if (a == x && b == y) {
                return dis[a][b];
            }

            // Try all 4 diagonal directions
            for (int i = 0; i < 4; i++) {

                int new_i = a + dx[i];
                int new_j = b + dy[i];

                // Bishop can travel multiple squares
                while (new_i >= 0 && new_j >= 0 &&
                       new_i < n && new_j < m) {

                    if (dis[new_i][new_j] == -1) {

                        dis[new_i][new_j] = dis[a][b] + 1;

                        q.push({new_i, new_j});
                    }

                    new_i += dx[i];
                    new_j += dy[i];
                }
            }
        }

        return -1;
    }
};

