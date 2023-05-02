class Solution {
private:
    void permute(vector<int>& nums,vector<bool>& map,vector<int>& ds,vector<vector<int>>& ans){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i =0;i<nums.size();i++){
            if(map[i] != true){
                map[i] = true;
                ds.push_back(nums[i]);
                permute(nums,map,ds,ans);
            
                ds.pop_back();
                map[i] = false;
            
            }
            
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        
        vector<bool>map (n,false);
        
        vector<int>ds;
        vector<vector<int>>ans;
        
        permute(nums,map,ds,ans);
        return ans;
        
    }
};