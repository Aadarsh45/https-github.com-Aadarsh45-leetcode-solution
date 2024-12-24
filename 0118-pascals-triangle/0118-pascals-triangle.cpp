class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        res.push_back({1});
        if(n == 1) return res;

        for(int i = 1 ; i < n; i++){
            vector<int>temp(i+1,1);
            for(int j = 1 ; j < i ; j++){
                cout<<i<<" "<<j<<endl;
               int temp2 = res[i-1][j-1]+res[i-1][j];
               temp[j] = temp2;
            }
            res.push_back(temp);

        }
        return res;
        
    }
};