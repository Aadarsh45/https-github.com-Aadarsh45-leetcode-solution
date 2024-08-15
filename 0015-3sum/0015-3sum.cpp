class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();

        int i = 0;
        while(i<n-2){
            if (i > 0 && nums[i] == nums[i - 1]) {i++; continue; }
             int j = i+1;
             int k = n-1;
           
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                   vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                     j++;
                     k--;
                //skip the duplicates:
                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
            i++;

        }
        return ans;
        
    }
};