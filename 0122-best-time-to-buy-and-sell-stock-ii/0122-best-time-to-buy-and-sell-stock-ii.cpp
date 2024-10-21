class Solution {
public:
    int help(int i, int buy, vector<int>& prices, vector<vector<int>>& dp, int n) {
        if (i == n) return 0;

        if (dp[i][buy] != -1) return dp[i][buy];

        int op1 = 0, op2 = 0;
        if (buy == 1) {
            op1 = -prices[i] + help(i + 1, 0, prices, dp, n);
            op2 = help(i + 1, 1, prices, dp, n);
        } else {
            op1 = prices[i] + help(i + 1, 1, prices, dp, n);
            op2 = help(i + 1, 0, prices, dp, n);
        }
        return dp[i][buy] = max(op1, op2);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); // 2D memo table to store results
        return help(0, 1, prices, dp, n);
    }
};
