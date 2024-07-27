class Solution {
public:
    void bfs(int r,int c,vector<vector<int>>&vis ,vector<vector<int>>& image, int color,int ic){
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>>q;
        q.push({r,c});
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            image[r][c] = color;
            vis[r][c] = 1;
            q.pop();
            
            for(int i = 0;i<4;i++){
            
            int nr = r+dr[i];
            int nc = c+dc[i];
            
            if(nr>=0 && nc>=0 && nr <n && nc <m &&image[nr][nc] == ic && vis[nr][nc] == 0){
                q.push({nr,nc});
            }}
            
         }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        if(image[sr][sc] == color) {
            return image;
        }
        int ic = image[sr][sc];
        
        bfs(sr,sc,vis,image,color,ic);
        
        return image;
        
    }
};