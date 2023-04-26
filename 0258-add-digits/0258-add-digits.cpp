class Solution {
public:
    int cnt = 0;
    int addDigits(int num) {
       return 1 + (num - 1) % 9;
        
       }
};