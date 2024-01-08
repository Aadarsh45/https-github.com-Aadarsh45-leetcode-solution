class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int maxi = 0;               //maximum cosecutive ones
      int cnt = 0;
       
      for(int i =0;i<nums.size();i++){
        if(nums[i] == 0){
          
          maxi = max(maxi,cnt);
          cnt = 0;
        }
        else{
          cnt++;
        }
      }
      maxi = max(maxi,cnt);
      return maxi;
        
    }
};