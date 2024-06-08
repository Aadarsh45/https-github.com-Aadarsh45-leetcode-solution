class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // unordered_map<int,pair<int,int>> hash;
        // vector<int> v;
        int n = mat.size();
        int m = mat[0].size();
        int max = 0;
        int ansrow = -1;
        int anscol = -1;
        
        for(int i = 0;i < n*m;i++){
            int row = i/m;
            int col = i%m;
            // cout<<row<<" "<<col<<" "<<max<<endl;
            
            // v.push_back(mat[row][col]);
            // hash[mat[row][col]] = {row,col};
            if(mat[row][col] > max){
                 
                max = mat[row][col];
                ansrow = row;
                anscol = col;
                
            }
            
        }
        return {ansrow,anscol};
        
    }
};