class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return help(n-1,amount,coins,dp);
        
    }
    int help(int i,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(amount == 0){ return 1;}
        if(i == 0){
            if(amount%coins[i] == 0) {cout<<amount/coins[0]<<endl;return 1;}
            else {return 0;}
        }

        if(dp[i][amount]!=-1) return dp[i][amount];

        int take = 0;
        if(amount >= coins[i]) take = help(i,amount-coins[i],coins,dp);
        int not_take = help(i-1,amount,coins,dp);

        return dp[i][amount] = take+not_take;
    }
};