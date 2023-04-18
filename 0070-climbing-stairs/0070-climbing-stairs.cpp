class Solution {
public:
    int climbStairs(int n) {
       vector<int> arr(n+1, -1);
       
        
      return  help(n,arr);
        
        
        
    }
    int help(int n,vector<int>&arr){
        if(arr[n]!=-1){
            return arr[n];
        }
        if(n==1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        
        return arr[n]= help(n-1,arr) +  help(n-2,arr);
    }
};