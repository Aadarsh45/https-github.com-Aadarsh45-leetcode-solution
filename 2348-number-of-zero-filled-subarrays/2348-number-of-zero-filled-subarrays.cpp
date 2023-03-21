class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int size = nums.size();
        
       long long cnt = 0;
       bool flag = false;
        
        for (int i=0;i<size;i++){
           
            if( nums[i] == 0){
                cnt++;
                flag = true;
            }
            
            else{
                if(flag){
                    ans +=(cnt+1)*cnt/2;
                }
                cnt = 0;
                    
                }
        }
        if(cnt!=0){
             ans +=(cnt+1)*cnt/2;
        }
        
        return ans;
        
    }
};