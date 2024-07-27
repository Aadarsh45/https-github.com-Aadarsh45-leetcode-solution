class Solution {
public:
    bool dfs(int st,vector<int> adj[],vector<int>&vis,vector<int>&path){
        vis[st] = 1;
        path[st] = 1;
        
        
        for(auto it : adj[st]){
            if(vis[it] == 0){
                if(!dfs(it,adj,vis,path))
                    return false;
            }
            
            else if(path[it] == 1) return false;
        }
        path[st] = 0;
        return true;
        
            
        
    }
    bool canFinish(int N, vector<vector<int>>& nums) {
        std::vector<int> adj[N];
        
        for (int i = 0; i < nums.size(); i++) {
            adj[nums[i][1]].push_back(nums[i][0]);
        }
        
       vector<int>vis(N,0);
       vector<int>path(N,0); 
        
        for(int i = 0;i<N;i++){
            if(vis[i] == 0){
                if(dfs(i,adj,vis,path) == false){
                    return false;
                }
            }
        }
        
        return true;
    }
};