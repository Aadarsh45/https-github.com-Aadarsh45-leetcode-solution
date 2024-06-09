class Solution {
public:
    int sol(int i,int pre,vector<int>& nums,vector<vector<int>>&dp){
        if(i >= nums.size()) return 0;
        
        if(dp[i][pre]!=-1) return dp[i][pre];
        
        int take = 0;
        if(nums[i] > pre){
            take = nums[i] + sol(i+1,pre+nums[i],nums,dp);
        }
        int not_take = sol(i+1,pre,nums,dp);
        
        return dp[i][pre] = max(take,not_take);
    }
    int maxTotalReward(vector<int>& nums) {
       int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n + 1,vector<int>(4001,-1));
        
        return sol(0,0,nums,dp);

    }
};