class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 1)return nums[0];
        vector<int>dp(n,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2;i<n;i++){
            int pick = nums[i]+dp[i-2];
            int not_pick  = dp[i-1];
            dp[i] = max(pick,not_pick);
        }
        return dp[n-1];
        
    }
};

// int maxLootRec(vector<int> &hval, int n) {
    
//     // If no houses are left, return 0.
//     if (n <= 0)  return 0;
  
//       // If only 1 house is left, rob it. 
//     if (n == 1)  return hval[0];

//     // Two Choices: Rob the nth house and do not rob the nth house 
//     int pick = hval[n - 1] + maxLootRec(hval, n - 2);
//     int notPick = maxLootRec(hval, n - 1);

//     // Return the max of two choices
//     return max(pick, notPick);
// }