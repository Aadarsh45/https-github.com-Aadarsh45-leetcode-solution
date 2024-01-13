class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int pricesSize = prices.size();
       if(pricesSize==0||pricesSize==1){
        return 0;
    }
    int buy=prices[0],profit=0;
    int i=1;
   
  while(i<pricesSize){
      if(profit<prices[i]-buy){
         profit=prices[i]-buy;
      }
      if(prices[i]<buy){
          buy=prices[i];
        
      }
      i++;
   

}
    
    if(profit<=0){
        return 0;
    }
    
        return profit;
    }
};