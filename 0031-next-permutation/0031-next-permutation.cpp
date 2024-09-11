
class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // Find the first decreasing element
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i >= 0) {
            int j = n - 1;
            // Find the element just larger than nums[i]
            while (nums[j] <= nums[i]) {
                j--;
            }
            std::swap(nums[i], nums[j]);
        } else {
            // If no such element is found, reverse the entire array
            std::reverse(nums.begin(), nums.end());
            return;
        }
        
        // Reverse the elements from i+1 to the end of the array
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};