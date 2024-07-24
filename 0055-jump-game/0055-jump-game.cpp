class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        if((nums[0] == 0) && (n > 1 ))return false;
        if(nums[0] == n-1) return true;
        int cnt = nums[0];
        
        for(int i = 1;i<nums.size();i++){
            cnt = max(cnt,i+nums[i]);
            if(cnt == n-1){
                return true;
            }
            else if(cnt == i){
                return false;
            }
        }
        return true;
    }
};