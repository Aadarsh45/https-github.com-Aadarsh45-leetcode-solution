class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& nums) {
        int n = nums.size();
        // sort(nums.begin(),nums.end());
        
        double ans = 0;
        int temp = nums[0][0]+nums[0][1];
        ans+=nums[0][1];
        
        for(int i = 1;i<n;i++){
            temp = max(nums[i][0],temp);
            temp+=nums[i][1];
            int wt = temp - nums[i][0];
            ans+=wt;
        }
        ans = ans/n;
        return ans;
        
    }
};