class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxi = 1;
        int cnt = 1;
        
        for( int i = 1; i < nums.size() ; i++){
           if(nums[i] > nums[i-1]){
                cnt++;
            }
             else{
                maxi = max(maxi,cnt);
                cnt = 1;
            }
            
        }
        if(cnt>maxi){
            return cnt;
        }
        
        return maxi;
    }
};