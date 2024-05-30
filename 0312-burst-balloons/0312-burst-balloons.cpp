class Solution {
public:
//     int f(int i ,int j,vector<int>& nums,vector<vector<int>>&dp){
//         if(j < i) return 0;
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int maxi = INT_MIN;
//         // cout<<i<<" "<<j<<endl;
//         for(int ind = i;ind <= j;ind++){
           
//             int ans = nums[i-1]*nums[ind]*nums[j+1] + f(i,ind-1,nums,dp)+ f(ind+1,j,nums,dp);
            
            
//             maxi = max(maxi,ans);
            
//         }
        
//         return dp[i][j] = maxi;
//     }
    int maxCoins(vector<int>& nums) {
        int n =  nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1); 
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        
        for(int i =n;i>=1;i--){
            for(int j = i;j<=n;j++){
                int maxi = INT_MIN;
        // cout<<i<<" "<<j<<endl;
              for(int ind = i;ind <= j;ind++){
           
                  int ans = nums[i-1]*nums[ind]*nums[j+1] + dp[i][ind-1]+ dp[ind+1][j];
                  maxi = max(maxi,ans);
               }
               dp[i][j] = maxi;
                
            }
        }
        
        return dp[1][n];
        
    }
};