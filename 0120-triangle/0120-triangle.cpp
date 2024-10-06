class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 1)return triangle[0][0];

        vector<vector<int> > dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];

        for(int i = 1;i<n;i++){
            for(int j = 0;j<i+1;j++){
                int op2 = INT_MAX;
                int op1 = INT_MAX;
                if(j < i) op1 = dp[i-1][j]+triangle[i][j];
                if(j>0) op2 = dp[i-1][j-1]+triangle[i][j];
             

                dp[i][j] = min(op1,op2);

              
                // cout << op1 << " " << op2 << " " << i << " " << j << endl;

            }
        }
        int res = INT_MAX;
        for(int i = 0;i<n;i++){
            res = min(res,dp[n-1][i]);
            // cout<<res<<" ";

        }
        return res;
        
    }
};