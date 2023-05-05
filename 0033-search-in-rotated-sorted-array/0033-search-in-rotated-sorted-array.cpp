class Solution {
public:
    
    int solve(vector<int> &nums, int start, int end, int target){
        if(start > end) return -1;
        if(start == end){
            if(nums[start] == target) return start;
            return -1;
        }
        int mid = (end+start)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] > target) return solve(nums, start, mid-1, target);
        else if(nums[mid] < target) return solve(nums, mid+1, end, target);
        return 0;
    }
    
    int search(vector<int>& nums, int target) {
        int first = nums[0];
        sort(nums.begin(),nums.end());
        int ans = solve(nums, 0, nums.size()-1, target);
        int idx = solve(nums, 0, nums.size()-1, first);
        if(ans == -1) return ans;
        if(idx > ans) return nums.size()-(idx-ans);
        else return ans-idx;
    }
};