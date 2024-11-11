

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }
    
    int findprimee(int a, int b) {
        if (b == 1) {
            return a;
        }
        for (int  i = 2;i<a;i++) {
            if (isPrime(i) && (a - i) < b) {
                return a-i;
            }
        }
        return a; // If no valid prime is found, return a itself
    }
    
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] >= nums[i + 1]) {
                nums[i] = findprimee(nums[i], nums[i + 1]);
            }
        }
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
};
