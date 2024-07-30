class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight : flights) {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }

        // Min-heap: (cost, node, stops)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.emplace(0, src, 0);

        // 2D Distance array to track the minimum cost at each node with exact stops
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();

            // If destination is reached, return the cost
            if (node == dst) return cost;

            // If the number of stops is within the limit, explore further
            if (stops <= k) {
                for (auto& [next_node, price] : adj[node]) {
                    int new_cost = cost + price;

                    // Only push to queue if we find a cheaper way to reach next_node with stops+1
                    if (new_cost < dist[next_node][stops + 1]) {
                        dist[next_node][stops + 1] = new_cost;
                        pq.emplace(new_cost, next_node, stops + 1);
                    }
                }
            }
        }

        return -1; // Destination not reachable within k stops
    }
};
