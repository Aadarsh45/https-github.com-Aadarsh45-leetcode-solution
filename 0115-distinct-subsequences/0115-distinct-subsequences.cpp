class Solution {
public:
    // Constant for modulo operation
    const int MOD = 1e9 + 7;

    int numDistinct(string s, string t) {
        int n = s.length();   // Length of string s
        int m = t.length();   // Length of string t

        // Initialize a 2D dp vector with dimensions (n+1)x(m+1) and all values set to 0
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Base case: If t is an empty string, there is exactly one way to match it
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int take = 0;
                if (s[i-1] == t[j-1]) {
                    take = dp[i-1][j-1];
                }
                int not_take = dp[i-1][j];
                dp[i][j] = (take + not_take) % MOD;
            }
        }
        return dp[n][m];
    }
};
