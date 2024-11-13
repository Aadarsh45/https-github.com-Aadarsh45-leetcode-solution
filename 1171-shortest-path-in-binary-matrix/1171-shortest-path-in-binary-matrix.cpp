class Solution {
public:
    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}; 
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;if(n == 1) return 1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1,{0,0}});          //cost , coordinates

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;

        while(!q.empty()){
             auto [cost, pos] = q.front(); int x = pos.first, y = pos.second; q.pop();
            for (int i = 0; i < 8; i++) { 
            int newX = x + dx[i]; 
            int newY = y + dy[i]; 
            
            if (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 0) { 
                
                if(dist[newX][newY] > cost+1){
                    dist[newX][newY] = cost+1;
                    q.push({cost+1,{newX,newY}});

                }
                
            }
            
        }


        }
        return dist[n-1][n-1] == 1e9? -1:  dist[n-1][n-1] ;



        
        
    }
};