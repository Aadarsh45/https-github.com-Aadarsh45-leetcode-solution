class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        // Adjacency list representation of the graph
        vector<pair<int, int>> adj[n];
        for(const auto& road : roads) {
            int u = road[0], v = road[1], w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // Min-heap to store {time, node}
        using pii = pair<long, long>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0}); // Starting from node 0 with time 0
        
        // Time to reach each node and number of ways to reach each node
        vector<long long> time(n, 1e18); // 1e18 is like "infinity" for this context
        vector<int> ways(n, 0);
        time[0] = 0;
        ways[0] = 1;
        
        while (!pq.empty()) {
            auto [currTime, node] = pq.top();
            pq.pop();
            
            // If the current time is greater than the stored time, continue
            if (currTime > time[node]) continue;
            
            for (auto [nextNode, edgeWeight] : adj[node]) {
                long long newTime = currTime + edgeWeight;
                
                if (newTime < time[nextNode]) {
                    time[nextNode] = newTime;
                    pq.push({newTime, nextNode});
                    ways[nextNode] = ways[node]; // Update ways for shortest path
                } else if (newTime == time[nextNode]) {
                    // If found another shortest path
                    ways[nextNode] = (ways[nextNode] + ways[node]) % mod;
                }
            }
        }
        
        return ways[n - 1];
    }
};
