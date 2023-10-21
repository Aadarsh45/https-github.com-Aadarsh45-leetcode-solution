//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
   vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> ans;
        int startRow = 0;
        int endCol = c-1;
        int endRow = r-1;
        int startCol = 0;
        
        int total_element = r*c;
        int count = 0;
        
        while(count < total_element) {
            //Print Start Row
            for(int i=startCol; i<=endCol && count < total_element; i++) {
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++; // 1
            
            //Print End Col
            for(int i =startRow; i<= endRow && count < total_element; i++) {
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--; // 2
            
            //Print End Row
            for(int i= endCol; i>=startCol && count < total_element; i--) {
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;//2
            
            
            //Print Start Col
            for(int i=endRow; i>=startRow && count < total_element; i--) {
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++; //1
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
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends