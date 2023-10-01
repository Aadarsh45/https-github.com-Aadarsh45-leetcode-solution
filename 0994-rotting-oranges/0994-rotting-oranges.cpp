class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
                
       int n = grid.size();
       int m = grid[0].size();
       
       queue<pair<pair<int,int>,int>> q;
       vector<vector<int>> vis(n,vector<int> (m,0));
       int min_time = 0;
       int cnt_fresh = 0;
       
       for(int i = 0;i<n;i++){
           for(int j = 0;j< m;j++){
               if(grid[i][j] == 2 && !vis[i][j] ){
                   vis[i][j] == 2;
                   q.push({{i,j},0});
               }
               if(grid[i][j] == 1){
                   cnt_fresh++;
               }
               
           }
       }
       int cnt = 0;
       int delrow[] = {-1,0,1,0};
       int delcol[] = {0,1,0,-1};
       while(!q.empty()){
          
           int row = q.front().first.first;
           int col = q.front().first.second;
           int tm = q.front().second;
           min_time = max(min_time,tm);
           q.pop();
           for(int i =0;i<4;i++){
               int nr = row+delrow[i];
               int nc = col+delcol[i];
               if(nr>=0 && nr<n && nc>=0&& nc< m&& grid[nr][nc] == 1&& vis[nr][nc]!=2){
                   vis[nr][nc] = 2;
                   q.push({{nr,nc},tm+1});
                   cnt++;
                   
               }
               
           }
          
           
       } if(cnt!=cnt_fresh) {return -1;}
       return min_time;
        
    }
};