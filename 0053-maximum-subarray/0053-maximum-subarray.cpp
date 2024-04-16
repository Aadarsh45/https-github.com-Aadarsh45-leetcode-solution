class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int n = nums.size();
      if( n == 1){
        return nums[0];
      }
      int ans = INT_MIN;
      int sum = 0;
      for(int i =0;i<n;i++){
        sum+=nums[i];
        cout<<sum<<endl;
        if(sum<0){
          ans = max(ans,sum);
          cout<<ans;
          sum = 0;
        }
        else{
          ans = max(ans,sum);
        }
      }
     
      return ans;
    }
};