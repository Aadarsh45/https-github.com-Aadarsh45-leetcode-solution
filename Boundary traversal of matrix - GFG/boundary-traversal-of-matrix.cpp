//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
       vector<int> ans;
       
       int i =1;int j=0;
       
       if(n == 1 && m == 1){
           ans.push_back(matrix[0][0]);
           return ans;
       }
       if(n==1 && m!=0){
            for(int i=0; i<m; i++){
                ans.push_back(matrix[0][i]);
            }
            return ans;
        }
        
        if(m==1 && n!=0){
            for(int i=0; i<n; i++){
                ans.push_back(matrix[i][0]);
            }
            return ans;
        }
       ans.push_back(matrix[0][0]);
       if(i<m){
           for( i =1;i<m;i++){
               ans.push_back(matrix[0][i]);
               
           }
       }
       if(j<n){
          for( j =1;j<n-1;j++){
               ans.push_back(matrix[j][m-1]);
               
           }
       }
       
       if(i>0){
           for( i = m-1;i>0;i--){
               ans.push_back(matrix[n-1][i]);
           }
       }
       
       
       if(j>0){
           for( j = n-1;j>0;j--){
               ans.push_back(matrix[j][0]);
           }
       }
       
       
       
       
    
    return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends