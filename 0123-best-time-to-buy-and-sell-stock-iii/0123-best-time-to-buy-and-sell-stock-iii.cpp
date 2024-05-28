class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        for(int i = n-1;i>=0;i--){
            for(int j =0;j<2;j++){
                for(int k = 1;k<=2;k++){
                    long profit;
                    if(j == 0){
                      profit = max(-prices[i]+dp[i+1][1][k] , dp[i+1][0][k]);
                    }     
                    if(j == 1){
                      profit = max( prices[i]+dp[i+1][0][k-1] , dp[i+1][1][k]);
                    }
                    dp[i][j][k] = profit;
                    
                }
            }

        }
        
        return dp[0][0][2];
        
    }
};