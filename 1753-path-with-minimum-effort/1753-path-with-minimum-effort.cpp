

class Solution {
public:
    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Priority queue to store (effort, coordinates)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({0, {0, 0}}); // (effort, (x, y))

        vector<vector<int>> dist(n, vector<int>(m, 1e9+7));
        dist[0][0] = 0;

        while (!q.empty()) {
            auto [cost, pos] = q.top();
            int x = pos.first, y = pos.second;
            q.pop();

            if (x == n - 1 && y == m - 1) {
                return cost;
            }

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    int nc = max(cost, abs(grid[newX][newY] - grid[x][y]));
                    if (dist[newX][newY] > nc) {
                        dist[newX][newY] = nc;
                        q.push({nc, {newX, newY}});
                    }
                }
            }
        }

        return dist[n - 1][m - 1] == 1e9+7 ? -1 : dist[n - 1][m - 1];
    }
};
