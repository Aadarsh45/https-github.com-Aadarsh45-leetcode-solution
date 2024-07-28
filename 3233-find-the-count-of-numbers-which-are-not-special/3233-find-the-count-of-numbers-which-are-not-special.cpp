class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int cnt = 0;
        int ans = r - l + 1;

        // Finding all primes up to sqrt(r)
        int upperLimit = sqrt(r);
        vector<int> primes;
        vector<bool> isPrime(upperLimit + 1, true);

        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= upperLimit; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = i * i; j <= upperLimit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Check for special numbers in the range [l, r]
        for (int p : primes) {
            int specialNum = p * p;
            if (specialNum >= l && specialNum <= r) {
                cnt++;
            }
        }

        return ans - cnt;
    }
};

