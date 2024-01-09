class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       int n = nums.size();
       vector<int>pre(n,0);
       pre[0] = nums[0];
      
       for(int i =1;i<n;i++){       // prefix Sum
        pre[i]=pre[i-1]+nums[i];
         if(nums[i-1] == nums[i] && nums[i] == 0){
           return true;
         }
         
       }
      
      unordered_map<int ,int>mp;
    
      
      for(int i =0;i<n;i++){
        
        if( pre[i]%k == 0 && i != 0 ) {return true;}
        cout<<pre[i]%k<<" ";
        
        if(mp.find(pre[i]%k) != mp.end()){
          if(i- mp[pre[i]%k] >1){
            return true;
          }
        }
        else{
        mp[pre[i]%k] = i;
        }
        cout<<i<<" "<<mp[pre[i]%k]<<endl;
       }
      return false;
      
        
    }
};