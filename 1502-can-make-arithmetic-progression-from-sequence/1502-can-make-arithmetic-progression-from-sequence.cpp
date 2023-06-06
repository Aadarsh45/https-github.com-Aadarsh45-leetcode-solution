class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
       int n = arr.size();
        sort(arr.begin(),arr.end());
         int diff = arr[1]-arr[0];
        if(n <= 2){
            return true;
        }
       
        int i = 2;
        
        while( i < n){
            if(arr[i]-arr[i-1] != diff){
               return false;
                
            }
            i++;
        }
        return true;
    }
};