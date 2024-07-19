class Solution {
public:
    int help(int i, int j, int n, int m, vector<vector<int>>& grid) {
        // If the ball has reached the last row, return the column index.
        if (i == n) return j;

        // Check for boundaries and directions.
        if (j < 0 || j >= m) return -1;  // Ball out of grid
        if ((j == 0 && grid[i][j] == -1) || (j == m - 1 && grid[i][j] == 1)) return -1;

        // Check the grid for the ball direction
        if (grid[i][j] == 1) {
            if (j + 1 < m && grid[i][j + 1] == 1) {  // Check the right direction
                return help(i + 1, j + 1, n, m, grid);
            }
        } else if (grid[i][j] == -1) {
            if (j - 1 >= 0 && grid[i][j - 1] == -1) {  // Check the left direction
                return help(i + 1, j - 1, n, m, grid);
            }
        }

        // If the ball is stuck, return -1.
        return -1;
    }

    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> result(m, -1);  // Initialize result with -1

        for (int j = 0; j < m; j++) {
            result[j] = help(0, j, n, m, grid);
        }

        return result;
    }
};
