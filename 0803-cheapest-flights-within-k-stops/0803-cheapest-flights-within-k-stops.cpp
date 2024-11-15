class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

     for (auto& flight : flights) { int s = flight[0], d = flight[1], c = flight[2]; adj[s].push_back({d, c});}

        vector<int>dist(n,1e9);
        dist[src] = 0;
        queue<tuple<int, int, int>> pq;
         pq.push({0, src, 0});

        while(!pq.empty()){
            auto [cost , node,step] = pq.front();
            cout<<node<<" "<<dist[node]<<endl;
            pq.pop();
           
            
            if(step > k)continue;
             

            for(auto it: adj[node]){
                if( cost+ it.second < dist[it.first] ){
                    dist[it.first] = cost + it.second;
                    pq.push({cost + it.second,it.first,step+1});
                }
            }
        }
       

        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
        
    }
};