class Solution {
public:
bool isBipartite(vector<vector< int>>& graph) {
vector< int> color(graph.size(),-1);
queue< int> q;

    for(int i=0;i<color.size();i++){
        if(color[i]==-1){
                    q.push(i);
    color[i]=0;
    while(!q.empty()){
        int n=q.front();
            q.pop();
        for(auto it: graph[n]){
            if(color[it]==-1){
                color[it]=!color[n];
                q.push(it);
            }
            else{
                if(color[it]==color[n])
                    return false;
            }
        }
    }}}
    return true;
   }
};