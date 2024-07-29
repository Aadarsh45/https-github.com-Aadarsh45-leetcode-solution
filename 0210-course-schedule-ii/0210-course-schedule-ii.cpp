class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& pre) {
       
        
        int n = pre.size();
        vector<int> adj[V];
         
        
        vector<int>indeg(V,0);
        vector<int>v;
        
        for(int i = 0;i<n;i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            indeg[pre[i][0]]++;
           
        }
        queue<int>q;
        
        
        for(int i = 0;i<V;i++){
            
            if(indeg[i] == 0){
                cout<<i;
                q.push(i);
            }
        }
        
        vector<int>ans;
        
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }
        
       if(ans.size()<V)return{};
          
        
        return ans;
        
    }
};