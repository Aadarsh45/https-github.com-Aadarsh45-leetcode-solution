class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int sum = 0;
      int temp = 0;
      int n = nums.size();
      temp = (n*(n+1))/2;
      
      for(int i =0;i<nums.size();i++){
        sum+=nums[i];
      }
      cout<<abs(sum-temp);
      
      return abs(sum-temp);
        
    }
};