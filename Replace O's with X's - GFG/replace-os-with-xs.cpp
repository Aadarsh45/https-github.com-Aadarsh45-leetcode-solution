//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution{
    private:
     void dfs(int r,int c,vector<vector<int>> &vis,vector<vector<char>>& mat,int delrow[],int delcol[]){
         vis[r][c] = 1;
         int n = mat.size();
         int m = mat[0].size();
         for(int i =0;i<4;i++){
            int nr = r+delrow[i];
            int nc = c+delcol[i];
            if(nr>=0 && nr<n && nc>=0&& nc<m  && !vis[nr][nc] && mat[nr][nc] == 'O'){
                     dfs(nr, nc, vis, mat, delrow, delcol);
                 }
             }
         }
     
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
         int delrow[] = {-1,0,1,0};
         int delcol[] = {0,1,0,-1};
        
        // boundary traversal check for zero
        
        for(int i = 0;i<m;i++){
            
            if(!vis[0][i] && mat[0][i] == 'O'){
                dfs(0,i,vis,mat,delrow,delcol);
            }
            if(!vis[n-1][i] && mat[n-1][i] == 'O'){
               dfs(n-1,i,vis,mat,delrow,delcol);
            }
           
        }
        for(int i = 0;i<n;i++){
             if(  !vis[i][0]&&mat[i][0] == 'O' ){
                dfs(i,0,vis,mat,delrow,delcol);
               }
            if( !vis[i][m-1]&&mat[i][m-1] == 'O'){
                dfs(i,m-1,vis,mat,delrow,delcol);
            }
        }
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j] == 0 && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends