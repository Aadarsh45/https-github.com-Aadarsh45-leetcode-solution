#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[i] = true;
        for (auto it : adj[i]) {
            if (!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& nums) {
        int n = nums.size();

        // Create an adjacency list
        vector<vector<int>> adj(n); 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (nums[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        // Perform DFS to count connected components
        int cnt = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adj, vis);
            }
        }

        return cnt;
    }
};
