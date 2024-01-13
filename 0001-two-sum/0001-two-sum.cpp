class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int>hash;
      int n = nums.size();
      
      for(int i =0;i<n;i++){
        if(hash.find(target-nums[i])!=hash.end()){
          return {i,hash[target-nums[i]]};
        }
        else{
          hash.insert({nums[i],i});
        }
      }
      return {};
        
    }
};