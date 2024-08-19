class Solution {
public:
    int help(int n,int len,int paste,vector<int>&dp){
        if(len > n) return 1000;
        if(len == n) return 0;

        int cpy = 2+help(n,len*2,len,dp);
        int p = 1+help(n,len+paste,paste,dp);

        return min(cpy,p);
        
        
        
    }
    int minSteps(int n) {
        if(n == 1)return 0;

        vector<int> dp(n+1,n+1);
        return 1+ help(n,1,1,dp);
        
    }
};