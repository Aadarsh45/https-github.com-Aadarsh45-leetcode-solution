class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = -1e9;
        int temp = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            temp += nums[i];
            if(temp < 0){
                sum = max(sum,temp);
                temp = 0;
                continue;
            }
            sum = max(sum,temp);
        }
        return sum;
    }
};