class Solution {
public:
    int help(int i,vector<int>& nums, int target,vector<vector<int>>&dp,int sum){
        if(i == 0){
            if(nums[i] == 0 && target == 0)return 2;
            else if(nums[i] == abs(target))return 1;
            else return 0;
        }
          if (target + sum < 0 || target + sum > 2 * sum) return 0;
        if(dp[i][target+sum] != -1) return dp[i][target+sum];

        int p = help(i-1,nums,target-nums[i],dp,sum);
        int n = help(i-1,nums,target+nums[i],dp,sum);
        return dp[i][target+sum] = p+n;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto it:nums)sum+=it;

        vector<vector<int>>dp(n+1,vector<int>(2*sum+1,-1));
        return help(n-1,nums,target,dp,sum);
        
    }
};