class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
           return nums[0];
        }
        int res = nums[0];
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
            res = max(res,sum);
            if(sum < 0){
               sum = 0;
               continue;
            }
            
        }
        if(sum!= 0)
        {res = max(res,sum);}
        return res;
    }
};