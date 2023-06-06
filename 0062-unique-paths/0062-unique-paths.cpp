class Solution {
public:
    int help(int m,int n,vector<vector<int>>&dp){
        
        
        if(m == 0 && n ==0) {
            return  1;
        }
        if(m<0 || n<0){
            return  0;
        }
        if(dp[m][n] != -1) return  dp[m][n];
       
         int  lft = help(m-1,n,dp); 
       
         int  up = help(m,n-1,dp);
      
        
        return dp[m][n] = up+lft;
        
       
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp( m, vector<int> (n, -1)); //create a vector on size m*n
        dp[0][0] = 1;
        
        return help(m-1,n-1,dp);
    }
};