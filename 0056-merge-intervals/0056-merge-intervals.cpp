class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        vector<vector<int>> res;

        while(i<nums.size()){
            int j = i;
            int st = nums[i][0];
            int end = nums[i][1];
            while(j<nums.size() && end >= nums[j][0]){
                end = max(end,nums[j][1]);
                j++;
            }
            res.push_back({st,end});
            i=j;

        }
        return res;

        
    }
};