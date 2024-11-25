class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
         int n = nums.size();
        int minSum = INT_MAX;
        bool found = false;

        for (int start = 0; start < n; ++start) {
            int sum = 0;
            for (int end = start; end < n; ++end) {
                sum += nums[end];
                int length = end - start + 1;
                if (length >= l && length <= r && sum > 0) {
                    minSum = min(minSum, sum);
                    found = true;
                }
            }
        }

        return found ? minSum : -1;
    }
};