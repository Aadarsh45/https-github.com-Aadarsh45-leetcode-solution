class Solution {
public:
    int  Common_Divisor(int a,int b){
           if (a == 0){
              return b;
           }
          return gcd(b % a, a);
    }
    int findGCD(vector<int>& nums) {
        int max = INT_MIN;
        int min = INT_MAX;
        
        for(int i=0 ; i<nums.size();i++){
            if(nums[i]>max){
                max = nums[i];
            }
            if(nums[i]<min){
                min = nums[i];
            }
        }
        
       return Common_Divisor(max,min);
        
        
    }
};