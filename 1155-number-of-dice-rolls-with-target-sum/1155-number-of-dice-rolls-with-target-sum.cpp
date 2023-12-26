const int MOD = 1e9 + 7;
const int N = 31;
const int M = 1001;
typedef long long int LLI;
class Solution {
public:
    int answers[N][N][M];

    int helper(int die, int k, int target) {
        if (target > k * die) return 0;
        if (die == 1) {
            return target <= k;
        }
        if (answers[die][k][target] > -1) return answers[die][k][target];
        LLI ans = 0;
        for (int i = 0; i <= k  &&  i <= target; i++) {
            ans += helper(die - 1, k, target - i);
            ans %= MOD;
        }

        return answers[die][k][target] = (ans % MOD);
    }

    int numRollsToTarget(int n, int k, int target) {
        if (n > target) return 0;
        memset(answers, -1, sizeof(answers));
        return helper(n, k - 1, target - n);
    }
};