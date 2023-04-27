class Solution {
public:
    int pivotInteger(int n) {
       long long sum1 = n*(n+1)/2;
        long long sum = 0;
       
        for(int i = 1 ; i <= n ; i++){
            sum+=i;
            if(sum == sum1){
                return i;
            }
            sum1 = sum1-(i);
            
        }
        return -1;
    }
};