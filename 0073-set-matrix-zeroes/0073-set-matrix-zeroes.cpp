class Solution {
public:
    void row(int i,vector<vector<bool>>& vec,vector<vector<int>>& matrix){
        
        for(int k = 0;k<vec[0].size();k++){
            if(matrix[i][k] != 0){
                vec[i][k] = false;
            }
        }
    }
    
    void col(int j,vector<vector<bool>>& vec,vector<vector<int>>& matrix){
        for(int k = 0;k<matrix.size();k++){
            if(matrix[k][j] != 0){
                vec[k][j] = false;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool> >vec( m, vector<bool> (n, true)); 
        
        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row(i,vec,matrix);
                    col(j,vec,matrix);
                }
            }
        }
        
        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vec[i][j] == false){
                    matrix[i][j]=0;
                }
            }
        }
        

        
    }
};