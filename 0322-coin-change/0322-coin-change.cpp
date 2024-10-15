class Solution {
public:
    int help(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (amount == 0) return 0;
        if (i == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            else return INT_MAX;
        }
        
        if (dp[i][amount] != -1) return dp[i][amount];
        
        int t = INT_MAX;
        if (coins[i] <= amount) {
            int res = help(i, coins, amount - coins[i], dp);
            if (res != INT_MAX) {
                t = 1 + res;
            }
        }
        int nt = help(i - 1, coins, amount, dp);
        return dp[i][amount] = min(t, nt);
    }

    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int res = 1e9+7;
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        res = min(res,help(n-1,coins,amount,dp));
        
        return res == 1e9+7 ? -1 : static_cast<int>(res);
        
    }
};