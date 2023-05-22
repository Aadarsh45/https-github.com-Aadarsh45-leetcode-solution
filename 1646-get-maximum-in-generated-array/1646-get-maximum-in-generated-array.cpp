class Solution {
    public:

    int getMaximumGenerated(int n) {
        if (n < 2) return n;
        vector<int> dp(n+1);
        int m = INT_MIN;
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (i % 2 == 1) dp[i] = dp[i / 2] + dp[i / 2 + 1];
            else dp[i] = dp[i / 2];
            m = max(dp[i], m);
        }
        return m;
    }
};
