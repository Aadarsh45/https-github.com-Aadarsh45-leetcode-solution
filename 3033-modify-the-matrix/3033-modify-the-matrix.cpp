class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();

      vector<int>temp(m,0);
      
      for(int i = 0;i<m;i++){
        for(int j =0;j<n;j++){
          temp[i] = max(temp[i],matrix[j][i]);
          cout<<matrix[j][i]<<" ";
        }
        cout<<endl;
      }
      for(int i =0;i<m;i++){
        cout<<temp[i]<<" ";
      }
      for(int i = 0;i<m;i++){
        for(int j =0;j<n;j++){
          if(matrix[j][i]== -1){
            matrix[j][i] = temp[i];
            // cout<<temp[i]<<" "<<temp[j]<<endl;
          }
        }
      }
      
      
      
      
      return matrix;
    }
};


