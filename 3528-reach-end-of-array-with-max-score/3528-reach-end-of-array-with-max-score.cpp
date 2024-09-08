class Solution {
public:
    long long findMaximumScore(std::vector<int>& nums) {
        long long ans = 0;
        long long curr = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            ans += curr;
            curr = std::max(curr, static_cast<long long>(nums[i]));
        }
        return ans;
    }
};

// score = (j-i)*nums[i]  jump from i to j
//maximise the score
// jump condn =  jump to indices greater than your current index.