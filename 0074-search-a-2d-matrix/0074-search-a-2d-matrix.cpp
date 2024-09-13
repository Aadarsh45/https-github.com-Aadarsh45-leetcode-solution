class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int st = 0;int end = n*m-1;
        while(st <= end){
           int mid = st +(end-st)/2;
           int r = mid/m;
           int c = mid%m;
           if(matrix[r][c] == target){
             return true;
           }
           else if(matrix[r][c] > target){
               end = mid-1;
           }
           else{
              st = mid+1;
           }

        }
        return false;
        
    }
};