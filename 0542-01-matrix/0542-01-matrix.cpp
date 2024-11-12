class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Initialize the result matrix with -1 for 1s and 0 for 0s.
        vector<vector<int>> res(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        
        // Push all cells with 0 into the queue and mark them in the result.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // BFS from all 0s to calculate the distance to the nearest 0 for each cell.
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && res[nr][nc] == -1) {
                    res[nr][nc] = res[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        return res;
    }
};
