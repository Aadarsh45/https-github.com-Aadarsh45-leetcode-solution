class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> vec(n/3 , vector<int> (3)); 
        int cnt = 0;
        int first;
        
        for(int i =0;i<nums.size();i++){
            if(i %3 == 0){
                first = nums[i];
            }
            if(nums[i] - first > k ) return {};
            
            else{
                vec[i/3][i%3] = nums[i];
            }
          
        }
        
        return vec;
        
    }
};