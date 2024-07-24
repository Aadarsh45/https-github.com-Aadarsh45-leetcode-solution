class Solution {
public:
    bool helper(int ind, int cnt,  string s,vector<vector<int>>&dp){
        if(ind==s.length()){
            if(cnt==0) return true;
            else return false;
        }
        if(dp[ind][cnt] != -1) return dp[ind][cnt];
        if(s[ind] == ')'){
            if(cnt==0) return dp[ind][cnt] = false;
            else return dp[ind][cnt] = helper(ind+1,cnt-1,s,dp);
        }
        else if(s[ind] == '(') return dp[ind][cnt] =  helper(ind+1,cnt+1,s,dp);
        else{
            bool open = helper(ind+1, cnt+1,s,dp);
            bool close = false;
            bool empty = helper(ind+1,cnt,s,dp);
            if(cnt>0) close = helper(ind+1,cnt-1,s,dp);
            return dp[ind][cnt] = open or close or empty;
        }
        return true;


    }
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.length() , vector<int>(s.length() , -1));
        return helper(0,0,s,dp);
    }
};