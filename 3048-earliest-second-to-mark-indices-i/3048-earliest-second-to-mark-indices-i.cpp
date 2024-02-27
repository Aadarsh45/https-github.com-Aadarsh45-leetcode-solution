class Solution {
public:
    
    bool helper(vector<int> &nums,vector<int> &change,int f){
       
       map<int,int> mp;
        
       for(int i = 0;i<=f;i++){
           mp[change[i]] = i;
       }
       cout<<f<<" ";
       int total = 0, mark = 0;
       for(int i = 0;i <= f; i++){
           if(mp.count(change[i]) && (i == mp[change[i]])){
               if(nums[change[i]-1] > total) return false;
               total -= nums[change[i]-1];
               mark++;
           }else{
               total++;
           }
       }
        
        
        
        return mark == nums.size();
        
        
    }
    
    
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& change) {
        
        
        
        
        int i = 0, j = change.size()-1;
        int ans = -1;
        while(i <= j){
            int mid = (i + j) / 2;
            if(helper(nums,change,mid))
            {
                ans = mid;
                j = mid - 1;
            }else{
                i = mid + 1;
            }
        }
        return ans == -1 ? -1 : ans+1;
        
        
        
        
        
    }
};