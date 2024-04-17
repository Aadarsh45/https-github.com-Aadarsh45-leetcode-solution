class Solution {
public:
    int maxProfit(vector<int>& p) {
      int n = p.size();
      if(n == 1) return 0;
      
      vector<int> pre(n,0);
      
      pre[n-1] = p[n-1];
      for(int i =n-2;i>=0;i--){
        pre[i] = max(pre[i+1],p[i]);
      }
      int maxProfit = 0;
      for(int i =0 ;i<n-1;i++){
        int temp = pre[i+1]-p[i];
        maxProfit = max(maxProfit,temp);
      }
      
      return maxProfit;
      
    }
};