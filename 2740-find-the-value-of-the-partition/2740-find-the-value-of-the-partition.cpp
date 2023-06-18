class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int mini = INT_MAX;
        
        for(int i =0 ;i < nums.size()-1;i++){
            mini = min((nums[i+1]-nums[i]),mini);
        }
        return mini;
        
    }
};