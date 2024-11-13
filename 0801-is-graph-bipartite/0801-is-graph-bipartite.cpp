class Solution {
public:
   bool dfs(int node,vector<vector<int>>&graph,vector<int>&color){
      stack<int>stk;
      stk.push(node);
    
      color[node] = 0;

      while(!stk.empty()){
        int curr = stk.top();
        stk.pop();
        int col = color[curr];

        for(auto it: graph[curr]){
            if(color[it] == -1) {
                color[it] = abs(1-col);
                stk.push(it);
                
            }
            else if(color[it] == color[curr]) return false;
            
            
        }


      }
      return true;
   }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
       
        vector<int>color(n,-1);

        for(int i = 0;i<n;i++){
            if(color[i] == -1){
                if(!dfs(i,graph,color)) return false;
            }
        }
        return true;
    }
};