class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int>pre(n,0);
      pre[0] = nums[0];
      
      for(int i =1;i<n;i++){       // prefix Sum
        pre[i]+=pre[i-1]+nums[i];
      }
      
      unordered_map<int ,int>mp;
      int ans = 0;
      for(int i =0;i<n;i++){
        if(pre[i] == k) {ans++;}
        
        if(mp.find(pre[i]-k)!=mp.end()){
          ans+=mp[pre[i]-k];
        }
        
        mp[pre[i]]++;
      }
      return ans;
      
    }
};

//Brute Force TLE
// int i =-1;
//       int j =0;
//       int sum = 0;
//       int cnt = 0;
      
//       while(i<j && j<nums.size()){
//         if( sum == k){
//           cnt++;
//         }
//         else if(sum < k){
//           sum+=nums[j];
//           j++;
//         }
        
//         else {
//           i++;
//           sum-=nums[i];
          
//         }
//       }
//       if(sum == k){ cnt++;}
      
//       return cnt;