class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int n = nums.size();
      unordered_map<int,int> mp;
      for(int i =0;i<n;i++){
        mp[nums[i]]++;
      }
      int ans = 0;
      int temp = n/2;
      for(auto it: mp){
        if(it.second > temp ){
          ans = it.first;
          break;
        }
      }
      return ans;
        
    }
};