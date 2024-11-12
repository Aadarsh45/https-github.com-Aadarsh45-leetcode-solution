
class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    
    bool check(int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        // Count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<tuple<int, int, int>> q;

        // Initialize queue with all rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 1;
                    q.push({i, j, 0});
                }
            }
        }

        int min_tm = 0;

        while (!q.empty()) {
            auto [r, c, t] = q.front();
            min_tm = max(t, min_tm);
            q.pop();

            for (auto it : dir) {
                int nr = r + it[0];
                int nc = c + it[1];

                if (check(nr, nc, n, m) && !vis[nr][nc] && grid[nr][nc] == 1) {
                    cnt--;
                    vis[nr][nc] = 1;
                    q.push({nr, nc, t + 1});
                }
            }
        }

        if (cnt > 0) {
            return -1;
        }
        return min_tm;
    }
};
