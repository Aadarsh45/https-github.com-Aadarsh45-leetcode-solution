class Solution {
public:
    long long getCost(vector<vector<pair<char, int>>>& g, int start, int end){
    long long res= LONG_MAX; 
    vector<long long> vis(26, LONG_MAX);  vis[start] = 0;
    queue<pair<int, long long>> q;        q.push({start, 0});
    while(q.size()){
        auto [node, cost] = q.front(); q.pop();
        for(auto [n, c]: g[node]){            // iterate over all nodes connected to the node
            if(cost + c >= vis[n]) continue;  // if the current path cost is greter than what we have before then skip to next node.
            q.push({n, cost + c});            // push the current mode to queue with the updated path cost
            vis[n] = cost + c;                // update visited array cost as well
            if(n == end) res = cost + c;      // check if the node is equal to end node, if so keep tracking the min cost.
        }
    }
    return (res == LONG_MAX)?-1: res;
}

long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    long long ans = 0;
    unordered_map<long long, long long> costMap;
    vector<vector<pair<char, int>>> g(26);
    for(int i = 0; i < cost.size(); ++i) {   //Create the weighted directed graph from the given data
        g[original[i]-'a'].push_back({changed[i]-'a', cost[i]});  
    }
    for(int i = 0; i < source.size(); ++i){  // now check for the cost to make both string equal
        if(source[i] == target[i]) continue;
        long long t = 0, hs = (source[i] - 'a')*100 + target[i] - 'a';
        if(costMap.find(hs) != costMap.end()) t = costMap[hs];   // first check in hash map if the pair is already present or not. If available then use it
        else {                               // if cost was not yet calculated, then get the cost and update the hash map as well.
            t = getCost(g, source[i] - 'a', target[i] - 'a');  
            costMap[hs] = t; 
        }  
        if(t == -1) return -1;
        ans += t;
    }
    return ans;  
    }
};