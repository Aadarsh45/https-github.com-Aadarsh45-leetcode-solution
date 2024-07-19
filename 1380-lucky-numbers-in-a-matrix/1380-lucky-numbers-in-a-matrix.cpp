class Solution {
public:
    bool check(int i,int j,int n,int m, vector<vector<int>>& matrix){
        for(int k = 0;k<m;k++){
            if(matrix[i][j] > matrix[i][k]){
                return false;
            }
        }
        
        for(int k =0 ;k<n;k++){
            if(matrix[i][j] < matrix[k][j]){
                return false;
            }
        }
        return true;
    }
    vector<int> luckyNumbers (vector<vector<int>>&matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>ans;
        
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(check(i,j,n,m,matrix)){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
        
    }
};