class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        
        vector<vector<int>>vec(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
           
           for(int j = 0;j<m;j++){
               if(colSum[j] == 0){ continue;}
               else if(rowSum[i] > 0){
                   cout<<rowSum[i]<<" ";
                   vec[i][j] = min(colSum[j],rowSum[i]);
                   colSum[j]-=vec[i][j];
                   rowSum[i]-=vec[i][j];
                   cout<<i<<" "<<j<<" "<<vec[i][j]<<endl;
               }
               else{
                   break;
               }
           }
        }
        
        return vec;
    }
};