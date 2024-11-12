

class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    
    bool check(int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> res(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 'O') {
                res[i][0] = true;
                q.push({i, 0});
            }
            if (mat[i][m - 1] == 'O') {
                res[i][m - 1] = true;
                q.push({i, m - 1});
            }
        }
        for (int j = 1; j < m - 1; j++) {
            if (mat[0][j] == 'O') {
                res[0][j] = true;
                q.push({0, j});
            }
            if (mat[n - 1][j] == 'O') {
                res[n - 1][j] = true;
                q.push({n - 1, j});
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto it : dir) {
                int nr = r + it[0];
                int nc = c + it[1];
                if (check(nr, nc, n, m) && !res[nr][nc] && mat[nr][nc] == 'O') {
                    res[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (res[i][j] == false && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }
    }
};
