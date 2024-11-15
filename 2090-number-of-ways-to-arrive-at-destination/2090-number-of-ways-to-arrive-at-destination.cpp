class Solution {
public:
    const int mod = 1e9+7;


    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        
        for (auto road : roads) { int u = road[0], v = road[1], cost = road[2]; adj[u].push_back({v, cost}); adj[v].push_back({u, cost}); }
        
        vector<long long> dist(n, LLONG_MAX);
         vector<long long> ways(n, 0); 
         priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq; 
         dist[0] = 0; 
         ways[0] = 1; 
         pq.push({0, 0});

        while(!pq.empty()){
            auto [cost,node] = pq.top();
            pq.pop();

            for(auto it : adj[node]){
                if(cost+ it.second < dist[it.first]){
                    dist[it.first] = cost+it.second;
                    ways[it.first] = ways[node];
                    pq.push({cost+it.second,it.first});
                }
                else if(cost+ it.second == dist[it.first]){
                    ways[it.first] =(ways[it.first]+ ways[node])%mod;
                }
            }
        }

        return ways[n-1]%mod;
        
        
    }
};