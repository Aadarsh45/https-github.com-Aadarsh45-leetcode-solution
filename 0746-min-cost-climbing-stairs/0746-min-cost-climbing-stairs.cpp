class Solution {
public:
    int solve(vector<int>& cost,int n,vector<int>&dp){
        if(dp[n] != -1){
            return dp[n];
        }
            
       if (n < 2) {
           return cost[n];
       }
            
        return dp[n] =cost[n] + min(solve(cost,n-1,dp) , solve(cost,n-2,dp));
         
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        if(n==2) return min(cost[0],cost[1]);
        vector<int>dp(n+1,-1);
       
        return min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        
    }
};