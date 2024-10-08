class Solution {
public:
    int help(vector<int>&nums){
        int n = nums.size();
        if(n == 1)return nums[0];
        vector<int>dp(n,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2;i<n;i++){
            dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
            cout<<i<<" "<<dp[i]<<endl;
        }
        return dp[n-1];
    }
    int rob(vector<int>& input) {
        int n = input.size();
        if(n == 1)return input[0];

        vector<int> first(input.begin(), input.end() - 1);  // From 0 to n-2
        vector<int> second(input.begin() + 1, input.end());

        return max(help(first),help(second));
        
    }
};