class Solution {
public:
    int solve(int row,int col,vector<vector<int>>&dp){
      if(row == 0 && col == 0){return dp[0][0] = 1;}
      
      else if(row<0 || col<0){
        return 0;
      }
      else if(dp[row][col]!=0){
        return dp[row][col];
      }
      else{
        return dp[row][col] = solve(row-1,col,dp) + solve(row,col-1,dp);
      }
    }
    int uniquePaths(int m, int n) {
      int row = m-1;
      int col = n-1;
      vector<vector<int>>dp(m,vector<int>(n,0));
      
     return solve(row,col,dp);
     
    }
};