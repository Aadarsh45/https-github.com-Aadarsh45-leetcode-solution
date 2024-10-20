class Solution {
public:
    int lcs(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
       
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                int take = 0,nt = 0;
                if(s[i-1] == t[j-1]){
                    take = 1+dp[i-1][j-1];
                }
                else{
                    nt = max(dp[i][j-1],dp[i-1][j]);
                }

                dp[i][j] = max(take,nt);


            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.length(),m = word2.length();
        int r = (lcs(word1,word2));
        int ans = n+m - 2*r;

        return ans;
        
        
    }
};