class Solution {
public:
    // dp is a 3D array used for memoization to store results of subproblems
    vector<vector<vector<int>>> dp;
    
    // Helper function to calculate the maximum score Alice can achieve
    int score(bool alice, int idx, int M, vector<int>& piles) {
        // Base case: if we've reached the end of the piles, no more stones can be taken
        if (idx >= piles.size()) {
            return 0;
        }
        
        // Check if the result for this state is already computed
        if (dp[alice][idx][M] != -1) {
            return dp[alice][idx][M];
        }
        
        // Initialize the result based on whose turn it is
        int res = alice ? 0 : INT_MAX;
        int total = 0; // Total number of stones taken in this turn
        
        // Consider taking x piles where x ranges from 1 to 2 * M
        for (int x = 1; x <= 2 * M; ++x) {
            if (idx + x > piles.size()) { // If taking x piles exceeds available piles, stop
                break;
            }
            total += piles[idx + x - 1]; // Add stones from the current pile to total
            
            // Recursively calculate the score for the next state
            if (alice) {
                res = max(res, total + score(!alice, idx + x, max(M, x), piles));
            } else {
                res = min(res, score(!alice, idx + x, max(M, x), piles));
            }
        }
        
        // Store the result in the memoization array
        dp[alice][idx][M] = res;
        return res;
    }
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        // Initialize the memoization array with -1
        dp = vector<vector<vector<int>>>(2, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        
        // Start the game with Alice's turn, starting at index 0, with M initially set to 1
        return score(true, 0, 1, piles);
    }
};