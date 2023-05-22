class Solution {
public:
    int solve(vector<int>&nums){   
       
        int prev2 = 0;
        int prev1 = nums[0];
        
        
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
         vector<int> temp1(begin(nums), end(nums)-1);
        vector<int> temp2(begin(nums)+1, end(nums));
        
        
        return max(solve(temp1),solve(temp2));
    }
};