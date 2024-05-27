class Solution {
public:
    int solve(int n,int m,string s,string t,vector<vector<int>>&dp){
         if (n < 0) return m + 1;
         if (m < 0) return n + 1;
        
        if(dp[n][m]!= -1) return dp[n][m];
        
        if(s[n] == t[m]){ dp[n][m] = solve(n-1,m-1,s,t,dp);}
        else{
           
          dp[n][m] = 1+ min( (solve(n-1,m-1,s,t,dp)) ,min( (solve(n-1,m,s,t,dp)) , (solve(n,m-1,s,t,dp)) ) );
        }
        
        return dp[n][m];


    }
    int minDistance(string word1, string word2) {
        
        int n = word1.length(),m = word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        return solve(n-1,m-1,word1,word2,dp);
        
    }
};