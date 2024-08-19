class Solution {
public:
    int help(int n,int len,int paste,vector<vector<int>>&dp){
        if(len > n) return 1000;
        if(len == n) return 0;
        
        if(dp[len][paste]!= 0) return dp[len][paste];

        int cpy = 2+help(n,len*2,len,dp);
        int p = 1+help(n,len+paste,paste,dp);

        return dp[len][paste] =  min(cpy,p);
        
        
        
    }
    int minSteps(int n) {
        if(n == 1)return 0;

        vector<vector<int>>dp(n + 1, vector<int>(n / 2 + 1, 0));
        return 1+ help(n,1,1,dp);
        
    }
};