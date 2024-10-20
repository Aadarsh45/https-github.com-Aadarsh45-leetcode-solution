class Solution {
public:
    int mod = 1e9+7;
    int numDistinct(string s, string t) {
        int n = s.length();   //length of strings
        int m = t.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));           // dp 2d-vector tabulation approach
        for(int i = 0;i<=n;i++){
            dp[i][0] = 1;
        }
       
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                int take = 0;
                if(s[i-1] == t[j-1]){take = dp[i-1][j-1];}
                int not_take = dp[i-1][j];

                dp[i][j] = (take+not_take)%mod;
                

            }
        }

        return dp[n][m];
        
    }
};