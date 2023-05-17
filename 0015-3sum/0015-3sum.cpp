class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        if(nums.size()<3){
             return {};
        }
       
        
        for(int i=0;i<nums.size()-2;i++){
                if(nums[i]>0){
                break;
                 }
                 if(i>0 && nums[i]==nums[i-1]){
                    continue;
                }
                int hgh=nums.size()-1;
                int lo=i+1;
                int sum=0;
                while(lo<hgh){
                    sum=nums[i]+nums[hgh]+nums[lo];
                    if(sum>0){
                   hgh--;
                    }
                    if(sum<0){
                    lo++;
                    }
                   if(sum==0){
                    ans.push_back({nums[i],nums[lo],nums[hgh]});
                    int last_low_occurence = nums[lo] , last_high_occurence = nums[hgh];  
                    while(lo < hgh && nums[lo] == last_low_occurence){  
                        lo++;
                    }
                    while(lo < hgh && nums[hgh] == last_high_occurence){
                        hgh--;
                    }
                    }
                }
        }
        return ans;
        
    }
};