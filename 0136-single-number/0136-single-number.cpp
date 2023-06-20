class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        
       int x = 0;
       for(auto & it: nums){
           x ^= it;
       }
        
       return x;
    }
};