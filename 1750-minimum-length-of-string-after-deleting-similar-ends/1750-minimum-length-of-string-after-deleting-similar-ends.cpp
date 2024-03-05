class Solution {
public:
    int minimumLength(string s) {
      if(s.length() == 1){
        return 1;
      }
      int n = s.length();
      int lo = 0;
      int hgh = n-1;
      
      
      while(lo < hgh){
        if(s[lo] == s[hgh]){
          char a = s[lo];
          while(s[lo+1] == a ){
            lo++;
           }
          while(s[hgh - 1] == a && lo < hgh){
            hgh--;
         }
          lo++;
          hgh--;
          
        }
        else {
          break;
        }
      }
      int ans = hgh-lo+1;
      if(ans<0) return 0;
      
      return hgh-lo+1;}
        
    //  return right - left + 1;
};