// class Solution {
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int n = heights.size();
//         int m = heights[0].size();
        
//         priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > q;
//         vector<vector<int>> dist(heights.size(),vector<int>(heights[0].size(),INT_MAX));
//         q.push({0,{0,0}});
//         dist[0][0]=0;
        
//         int dr[] = {-1,0,1,0};
//         int dc[] = {0,-1,0,1};
              
//         while(!q.empty()){
//             auto [d, coordinate] = q.top(); q.pop();
//             auto [x, y] = coordinate;
            
//              if (x == n - 1 && y == m - 1)
//                 return d;
            
//             for(int i = 0;i<n;i++){
//                 int nx = x+dr[i];
//                 int ny = y+dc[i];
//                 if(nx>=0 && nx<n &&ny >=0 && ny< m){
//                     int diff = max(d,abs(heights[nx][ny] - heights[x][y]));
//                     if(diff < dist[nx][ny]){
//                          q.push({diff, {nx, ny}});
//                         dist[nx][ny] = diff;
//                     }
                   
//                 }
                
//             }
//         }
//         return 0;
        
//     }
// };

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        using pii = pair<int, pair<int, int>>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        q.push({0, {0, 0}});
        dist[0][0] = 0;
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        
        while (!q.empty()) {
            auto [d, coordinate] = q.top(); q.pop();
            auto [x, y] = coordinate;
            
            if (x == n - 1 && y == m - 1)
                return d;
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dr[i];
                int ny = y + dc[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int diff = max(d, abs(heights[nx][ny] - heights[x][y]));
                    if (diff < dist[nx][ny]) {
                        dist[nx][ny] = diff;
                        q.push({diff, {nx, ny}});
                    }
                }
            }
        }
        return 0;
    }
};
