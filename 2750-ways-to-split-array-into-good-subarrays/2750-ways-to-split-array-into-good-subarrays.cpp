class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size(),mod = 1e9 + 7,i = 0,cnt_zeros = 0;
        while(i < n && nums[i] == 0){ 
            i++;
           }
        if(i == n)  return 0;
        int ans = 1;
      
        while(i < n){
            if(nums[i] == 1){
                if(cnt_zeros)
                    ans = ((long)ans * (cnt_zeros + 1)) % mod;
                cnt_zeros = 0;
            }
            if(nums[i] == 0)
                cnt_zeros++;
            i++;
        }
        return ans;
    }
};