class Solution {
public:
    void help(int i,vector<int>& candidates, int target,vector<int>&temp,set<vector<int>>&res){
        if(target == 0){
            res.insert(temp);
            return;
        }
        if(i==candidates.size()) return;
       

        for (int j = i; j < candidates.size(); ++j) {
            if (j > i && candidates[j] == candidates[j - 1]) continue; // Skip duplicates
            if (candidates[j] > target) break; // No need to proceed further if the candidate is greater than the target
            temp.push_back(candidates[j]);
            help(j + 1, candidates, target - candidates[j], temp, res);
            temp.pop_back();
        }


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size()-1;
        sort(candidates.begin(),candidates.end());
        set<vector<int>>res;
        vector<int>temp;
        help(0,candidates,target,temp,res);
        return vector<vector<int>>(res.begin(),res.end());
        
    }
};