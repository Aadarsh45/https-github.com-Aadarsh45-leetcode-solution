class Solution {
public:
    int help(vector<int>&arr,int k){
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        for(int i = 0;i<n;i++){
            dp[i][0] = true;
        }
        if(arr[0] <= k){
            dp[0][arr[0]] = true;
        }

         for(int i = 1;i<n;i++){
            for(int target = 1;target<=k;target++){
                bool not_take = dp[i-1][target];
                bool take = false;
                if(arr[i] <= target)take = dp[i-1][target-arr[i]];
                
                dp[i][target] = take||not_take;
                
            }
            
        }
        return dp[n-1][k];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum%2 == 1)return false;
        sum = sum/2;

        return help(nums,sum);
        
    }
};