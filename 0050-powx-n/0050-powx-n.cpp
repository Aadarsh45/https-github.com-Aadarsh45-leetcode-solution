class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0) nn = -nn;
        if (n == INT_MIN) {
            nn = -(long long)INT_MIN; // Convert to positive safely
            ans = myPow(x, nn - 1); // Compute x^(INT_MIN + 1)
            return 1.0 / (ans * x); // Adjust for the extra multiplication
        }
        while (nn != 0) {
            if (nn % 2 != 0) {
                ans *= x;
                nn--;
            } else {
                x *= x;
                nn /= 2;
            }
        }
        if (n < 0) return 1.0 / ans;
        return ans;
    }
};
