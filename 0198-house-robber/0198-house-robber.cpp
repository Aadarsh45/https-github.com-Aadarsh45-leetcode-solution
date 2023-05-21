class Solution {
public:

//     int solve(vector<int>&nums,int n,vector<int>&dp){
        

//         if(n<0) return 0;

//         if(n==0) return  nums[0];    // base condition

//         if(dp[n]!=-1){
//             return dp[n];
//         }

//         int pick = nums[n] + solve(nums,n-2,dp);
//         int notpick = 0 + solve(nums,n-1,dp);

//         return dp[n] = max(pick,notpick);


//     }
    int rob(vector<int>& nums) {
//         int n = nums.size()-1;
        
        
//         vector<int>dp(n+1,-1);
        
//         return solve(nums,n,dp); int prev2 = 0;
        int prev1 = nums[0];
        int prev2 = 0;
        
        
        for(int i = 1; i<nums.size();i++){
            
            int take  = nums[i];
              if(i > 1) {
                  take+=prev2;
                  
              }
            
            int not_take = prev1;
            
            int curr = max(take,not_take);
            prev2=prev1;
            prev1=curr;
           
            
        }
        return prev1;
      
        
        
    }
};