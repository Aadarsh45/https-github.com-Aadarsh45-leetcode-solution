class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m = board[0].size();
        
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if((i == 0 || j==0 || i == n-1 || j==m-1) && (vis[i][j] == 0 && board[i][j] == 'O')){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        
        int dir[] = {0,-1,0,1,0};
        
        while(!q.empty()){
            auto [r,c] = q.front();q.pop();
            
            for(int i =0;i<4;i++){
                int nr = r+dir[i];
                int nc = c+dir[i+1];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc] == 0 && board[nr][nc] == 'O'){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j] == 0 ){
                    board[i][j] = 'X';
                }
            }
        }
        
        
        
    }
};