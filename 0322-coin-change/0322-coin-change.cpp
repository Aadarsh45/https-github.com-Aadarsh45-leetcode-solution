class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));
        
        // Initialize the first row of the DP table
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = i / coins[0];
            } 
        }
        
        // Fill the DP table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int t = INT_MAX;
                if (coins[i] <= j) {
                    int res = dp[i][j - coins[i]];
                    if (res != INT_MAX) {
                        t = 1 + res;
                    }
                }
                int nt = dp[i - 1][j];
                dp[i][j] = min(t, nt);
            }
        }
        
        int res = dp[n - 1][amount];
        return res == INT_MAX ? -1 : res;
    }
};
