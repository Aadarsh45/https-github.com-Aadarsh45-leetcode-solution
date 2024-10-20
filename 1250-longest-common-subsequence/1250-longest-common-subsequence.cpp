class Solution {
public:
    // int help(int i,int j,string s,string t,vector<vector<int>>&dp){
    //     if(i-1 < 0 || j-1 < 0){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1)return dp[i][j];

    //     int take = 0;
    //     if(s[i-1] == t[j-1]){
           
    //         take = 1 + help(i-1,j-1,s,t,dp);

    //     }
    //     int nt = max(help(i-1,j,s,t,dp),help(i,j-1,s,t,dp));

    //     return dp[i][j] = max(take,nt);
    // }
    int longestCommonSubsequence(string s, string t) {
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
        //print the longest string 
        // int len = dp[n][m];
        // int i = n;
        // int j = m;

        // int index = len - 1;
        // string str = "";
        // for (int k = 1; k <= len; k++) {
        //    str += "$"; // dummy string
        // }

        // while(i > 0 && j > 0){
        //     if(s[i-1] == t[i-1]){
        //         str[index] = s[i-1];
        //     }
        //      else if (s[i - 1] > t[j - 1]) {
        //         i--;
        //     }   
        //     else j--;

        // }
        // cout<<str<<endl;



        return dp[n][m];

        
        
    }
};