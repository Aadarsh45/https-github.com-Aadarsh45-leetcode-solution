class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
       
        vector<vector<int> > dp(n, vector<int>(n,-1));
        for(int i = 0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }
        int res = INT_MAX;

        for(int i = 1;i<n;i++){
            for(int j = 0;j<n;j++){
                int op1 = INT_MAX,op2 = INT_MAX;
                if(j > 0)op1 = dp[i-1][j-1]+matrix[i][j];
                
                int op3 = dp[i-1][j]+matrix[i][j];
                if(j < n-1)op2 = dp[i-1][j+1]+matrix[i][j];

                dp[i][j] = min(op1,min(op2,op3));

                // cout<<op1<<" "<<op2<<" "<<op3<<" "<<i<<" "<<j<<endl;
                
            }
        }

        for(int i = 0;i<n;i++){
            res = min(res,dp[n-1][i]);
        }

        return res;



        
    }
};