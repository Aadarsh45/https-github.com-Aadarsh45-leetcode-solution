class Solution {
public:
    int alternateDigitSum(int n) {
      if(n == 0){
          return 0;
      }
      int sum1= 0;
     int cnt=0;
      int sum2=0;
      while(n!=0){
          cnt++;
          int a = n%10;
          if(cnt%2!=0){
            sum1+=a;
          }
          else{
              sum2+=a;
          }
          n=n/10;
      }
    int sum=0;
    if(cnt%2!=0){
        sum=sum1-sum2;
    }
     else{
          sum=sum2-sum1;  
        }
        
        return sum;
        
    }
};