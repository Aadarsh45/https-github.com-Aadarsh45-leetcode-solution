class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> row;
        vector<vector<int>> ans(1);
        for (const auto & num : nums) {
            if (row.count(num) == 0) { 
                // If we have not used this number yet
                ans[0].push_back(num);
                row[num] = 1;
            } else {
                // If number has already been used
                if (ans.size() < row[num] + 1) {
                    // If the row we need to push into does not exist
                    ans.push_back({num});
                } else ans[row[num]].push_back(num); // If it does exist
                row[num]++; // Update reference
            }
        }
        return ans;
    }
};