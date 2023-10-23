class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
         return ceil(log2(n) / log2(2)) == floor(log2(n) / log2(2));
    }
};
// log a base b = log2(n) / log2(b)