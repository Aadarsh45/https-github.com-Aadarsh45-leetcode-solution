class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), i = 0, flips = 0;
        while(i < n){
            nums[i] = (flips%2 == 1) ?  !nums[i] : nums[i];
            if(nums[i] == 0){
                flips++;
            }
            i++;
        }
        return flips;

    }
};