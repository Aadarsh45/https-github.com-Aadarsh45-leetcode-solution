class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int ans1 = 0, ans2 = 0;
        int n = grid.size(), m = grid[0].size();
        for(auto vec:grid)
        {
            int i = 0, j = m-1;
            while(i<j)
                if(vec[i++] != vec[j--]) 
                    ans1++;
        }
        for(int j=0;j<m;j++)
        {
            int a = 0, b = n-1;
            while(a < b)
                if(grid[a++][j] != grid[b--][j]) 
                    ans2++;
        }
        return min(ans1, ans2);
    }
};