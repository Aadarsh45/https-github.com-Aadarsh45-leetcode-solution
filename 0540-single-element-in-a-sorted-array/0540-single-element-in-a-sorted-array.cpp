class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[n-2] != nums[n-1]) return nums[n-1];
        int lo = 1;
        int hgh = n-2;
        
        int mid;
        while(lo <= hgh){
            mid = lo+(hgh-lo)/2;
            if(nums[mid-1]!= nums[mid] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if((mid%2 == 1 && nums[mid-1] == nums[mid])||(mid%2 == 0 && nums[mid] == nums[mid+1])){
                lo = mid+1;
            }
            else{
                hgh = mid-1;
            }
        }
        return -1;
    }
};