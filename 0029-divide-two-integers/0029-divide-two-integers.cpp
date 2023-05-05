class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == -2147483648 && divisor == -1) {
            return (2147483647);
        }
        long ans = dividend/divisor;
        if(ans<= INT_MIN){
            return INT_MIN;
        }
        if(ans >= INT_MAX){
            return INT_MAX;
        }
        return ans;
        
    }
};