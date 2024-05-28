class Solution {
public:
    int solve(int n,vector<int>& prices,int cap,vector<vector<vector<int>>>&dp,int cnt){
        if(cnt == 2 || n  == prices.size()) return 0;
        
        if(dp[n][cap][cnt] != -1) return dp[n][cap][cnt];
            
        long profit;
        if(cap == 0){
            profit = max(-prices[n]+solve(n+1,prices,1,dp,cnt) , solve(n+1,prices,0,dp,cnt));
        }
        else{
            profit = max( prices[n]+solve(n+1,prices,0,dp,cnt+1) , solve(n+1,prices,1,dp,cnt));
        }
        
        return dp[n][cap][cnt] =  profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
         vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        
        return solve(0,prices,0,dp,0);
        
    }
};