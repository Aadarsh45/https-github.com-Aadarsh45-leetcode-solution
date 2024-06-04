class Solution {
public:
    int solve(vector<int>& nums, int x){
        int n = nums.size();
        int lo = 0;
        int hgh = n-1;
        int mid;
        int ans = n;
        while(lo <= hgh){
            mid= lo+(hgh-lo)/2;
            if(nums[mid] >= x){
                ans = mid;
                hgh = mid-1;
            }
            else{
                lo = mid+1;
                
            }
        }
        return ans;
        
    }
    int searchInsert(vector<int>& nums, int target) {
        int a = solve(nums,target);
        
        return a;
        
    }
};