class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        
        unordered_set<int> Set;
        
        for(int i = 0; i<nums.size();i++){
            Set.insert(nums[i]);
            
        }
        bool ans = true;
       
        
        while(ans){
          if(Set.find(original) != Set.end()){
              original*=2;
          }
          else{
              ans = false;
          }
        }
        return original;
        
    }
};