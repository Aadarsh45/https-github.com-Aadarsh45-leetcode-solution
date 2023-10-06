class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        int count_of_3s = n / 3;
        int remainder = n % 3;
        
        if (remainder == 0) {
            return pow(3, count_of_3s);
        } else if (remainder == 1) {
            return pow(3, count_of_3s - 1) * 4;
        } else {
            return pow(3, count_of_3s) * 2;
        }
    }
};