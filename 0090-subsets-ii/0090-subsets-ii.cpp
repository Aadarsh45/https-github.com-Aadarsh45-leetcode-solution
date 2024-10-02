class Solution {
public:
    void help(vector<int>& nums, int i, vector<int>& temp, set<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        help(nums, i + 1, temp, ans);
        temp.pop_back();
        help(nums, i + 1, temp, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end()); // Sort the input to handle duplicates
        help(nums, 0, temp, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
