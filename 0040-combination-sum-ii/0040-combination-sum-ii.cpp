class Solution {
private:
    void combination_2(int idx,vector<int>& candidates, int target,vector<int>&ds,vector<vector<int>>&ans){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = idx ; i<candidates.size() ; i++){
           if(i>idx &&  candidates[i]==candidates[i-1]) {continue;}
           if(candidates[i] > target){ break;}
            
           if(candidates[i]<=target){
                ds.push_back(candidates[i]);
                combination_2(i+1,candidates,target-candidates[i],ds,ans);
                ds.pop_back();
            }
            
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        vector<int>ds;
        vector<vector<int>>ans;
        
        combination_2(0,candidates,target,ds,ans);
        
        return ans;
        
    }
};