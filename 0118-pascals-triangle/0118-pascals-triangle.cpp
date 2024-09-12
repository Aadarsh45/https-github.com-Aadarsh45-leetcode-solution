class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> res;
        if (n >= 1) res.push_back({1});
        if (n >= 2) res.push_back({1, 1});
        
        for(int i =2;i<n;++i){
            vector<int>temp(i+1,1);
            for(int j = 1;j<i;j++){
                temp[j] = res[i-1][j-1]+res[i-1][j];
                cout<<temp[j]<<" ";
            }
             res.push_back(temp);
             
        }
        return res;
      
    }
};