class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    
	int n = nums.size();
	for (int i = 1, a = 0, b = 0; i < n; i++) {
		if (nums[i] <= nums[i - 1]) {
			if (i - a >= k && b == a)
				a = i - k, b = i;
			else
				a = b = i;
		}
		if (i - a + 1 >= 2 * k ||
			b > a && i - b + 1 >= k)
			return true;
	}
	return false;}

};