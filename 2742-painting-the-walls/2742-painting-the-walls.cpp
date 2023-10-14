#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int paintWalls(std::vector<int>& cost, std::vector<int>& time) {
        const int kMax = 500'000'000; // A constant representing a very large value (effectively infinity)
        int n = cost.size(); // Get the number of walls
        // dp[i] := min cost to paint i walls by painters so far
        std::vector<int> dp(n + 1, kMax); // Create a dynamic programming array to store the minimum cost
        dp[0] = 0; // The minimum cost to paint 0 walls is 0 (base case)

        // Loop through each wall
        for (int i = 0; i < n; ++i) {
            // Loop through the dynamic programming array in reverse order
            for (int walls = n; walls > 0; --walls) {
                // Calculate the minimum cost to paint 'walls' walls using the current wall 'i'
                // The minimum cost at 'walls' is the minimum of:
                // - The cost of painting the current wall 'i' + the cost of painting the
                // previous walls within the time constraint (dp[walls - time[i] - 1])
                // - The cost of painting the previous walls without using the current wall 'i'
                // (dp[walls])
                dp[walls] = std::min(dp[walls], dp[std::max(walls - time[i] - 1, 0)] + cost[i]);
            }
        }
        return dp[n]; // The minimum cost to paint all 'n' walls is stored in dp[n]
    }
};