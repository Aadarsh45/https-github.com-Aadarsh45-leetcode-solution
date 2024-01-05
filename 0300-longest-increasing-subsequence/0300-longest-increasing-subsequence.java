class Solution {
    public int lengthOfLIS(int[] nums) {
        // Initialize an array dp with the same length as nums and fill it with 1s
        int[] dp = new int[nums.length];
        Arrays.fill(dp, 1);

        // Iterate through each element in nums
        for (int i = 1; i < nums.length; i++) {
            // Iterate through all previous elements
            for (int j = 0; j < i; j++) {
                // If nums[j] < nums[i], update dp[i]
                if (nums[j] < nums[i]) {
                    dp[i] = Math.max(dp[j] + 1, dp[i]);
                }
            }
        }

        // Find the maximum value in the dp array
        int maxLength = 0;
        for (int len : dp) {
            maxLength = Math.max(maxLength, len);
        }

        // Return the maximum value
        return maxLength;
    }
}