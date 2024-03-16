class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      int n = nums.size();
      if(n == 1){
        return 0;
      }
      int cnt = 0;
      int cnt0 = 0;
      
      unordered_map<int, int> hash; 
      hash[0] = -1;
      for(int i =0;i<n;i++){
        if(nums[i] == 0){
          cnt0++;
        }
        else{
          cnt0--;
        }
        cout<<cnt0<<"! ";
        if(hash.find(cnt0) == hash.end()){
          hash[cnt0] = i;
        }
        else{
          auto it = hash.find(cnt0);
          int idx = it->second;
          cout<<idx<<" ";
          cnt = max(cnt,i - idx);
        }
       

      }
      return cnt;
        
    }
};