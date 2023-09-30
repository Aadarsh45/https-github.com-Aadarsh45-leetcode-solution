class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // if(nums.size()<2 && nums[0]<=k){
        //     return 1;
        // }
        int last_occ = nums.size();
        unordered_set<int> s;
        int i;
        for( i = nums.size()-1;i>=0;i--){
            if(nums[i]<=k ){
                if( s.find(nums[i])!=s.end()){
                    continue;
                }
                else{
                    s.insert(nums[i]);
                    last_occ = i;
                }
                
            }
            
        }
        return nums.size()-last_occ;
    }
};