class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q; // min heap
        
        vector<vector<pii>> adj(n + 1);
        vector<int> dist(n + 1, 1e8);
        
        for (const auto& it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        dist[k] = 0;
        q.push({0, k});
        
        int maxDist = 0;
        
        while (!q.empty()) {
            auto [d, node] = q.top();
            q.pop();
            
            if (d > dist[node]) continue;
            
            for (const auto& it : adj[node]) {
                if (d + it.second < dist[it.first]) {
                    dist[it.first] = d + it.second;
                    q.push({dist[it.first], it.first});
                }
            }
        }
        
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == 1e8) return -1;
            maxDist = max(maxDist, dist[i]);
        }
        
        return maxDist;
    }
};
