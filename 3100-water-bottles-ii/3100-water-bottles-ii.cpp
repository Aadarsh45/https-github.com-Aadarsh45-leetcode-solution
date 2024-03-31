class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
      int ans= numBottles;
      int empty = ans;
      int exg=0;
      while(empty>=0){
        int temp = empty-numExchange;
        if(temp>=0){
          exg++;
          empty-=numExchange;
          numExchange++;
        }
        else{
          int t2 = temp+exg;
          if(t2>=0){
            ans+=exg;
            empty+=exg;
            exg= 0;
          }
          else{
            break;
          }
        }
      }
      ans+=exg;
      return ans;
    }
};