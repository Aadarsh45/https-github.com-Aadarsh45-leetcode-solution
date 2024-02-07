class Solution {
public:
    long long maximumSubarraySum(std::vector<int>& nums, int k) {
        int n = nums.size();
        long long maximumSum = -1e15; // Set initial maximum sum to a very small value
        
        map<int, int> numIndexMap; // Map to store the index of each number
        
        vector<long long> prefixSum(n); // Vector to store prefix sums
        prefixSum[0] = nums[0]; // Initialize the prefix sum
        
        // Calculate prefix sums
        for(int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        
        numIndexMap[nums[0]]=0;// Initialize the map
        
        // Iterate through the array
        for(int i = 1; i < n; i++) {
            long long target1 = nums[i] + k; // Define target 1
            long long target2 = nums[i] - k; // Define target 2
            
            // Check if target 1 exists in the map
            if(numIndexMap.find(target1) != numIndexMap.end()) {
                long long currentSum = prefixSum[i] - prefixSum[numIndexMap[target1]] + nums[numIndexMap[target1]];
                maximumSum = max(maximumSum, currentSum);
            }
            
            // Check if target 2 exists in the map
            if(numIndexMap.find(target2) != numIndexMap.end()) {
                long long currentSum = prefixSum[i] - prefixSum[numIndexMap[target2]] + nums[numIndexMap[target2]];
                maximumSum = max(maximumSum, currentSum);
            }
            
            // Update map with current number and its index
            if(numIndexMap.find(nums[i]) != numIndexMap.end()) {
                if(prefixSum[i] >= prefixSum[numIndexMap[nums[i]]]) continue;
            }
            numIndexMap[nums[i]] = i;
        }
        
        // If maximum sum is not updated, return 0
        if(maximumSum == -1e15) return 0;
        
        return maximumSum;
    }
};