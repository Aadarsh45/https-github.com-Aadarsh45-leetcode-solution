class Solution {
public:
    bool fun(int i, int j, vector<vector<int>>& grid, int health, vector<vector<vector<int>>>& dp,vector<vector<int>>&visited) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return health >= 1;
        }

        if (dp[i][j][health] != -1) {
            return dp[i][j][health];
        }

        int row[4] = {0, -1, 0, 1};
        int col[4] = {1, 0, -1, 0};
        bool ans = false;

        for (int k = 0; k < 4; k++) {
            int nrow = i + row[k];
            int ncol = j + col[k];

            if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && visited[nrow][ncol]!=1) {
                visited[nrow][ncol]=1;
                if (grid[nrow][ncol] == 0) {
                    bool curr = fun(nrow, ncol, grid, health, dp,visited);
                    if (curr) ans = true;
                } else if (grid[nrow][ncol] == 1 && health > 1) {
                    bool curr = fun(nrow, ncol, grid, health - 1, dp,visited);
                    if (curr) ans = true;
                }
                visited[nrow][ncol]=0;
            }
        }
        return dp[i][j][health] = ans;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        if(grid[0][0]==1){
            health--;
        }
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(health + 1, -1)));
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        return fun(0, 0, grid, health, dp,visited);
    }
};