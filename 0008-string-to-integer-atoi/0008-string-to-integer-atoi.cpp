class Solution {
public:
    int myAtoi(string s) {
        //int number = (int(charvalue)+0);
      long long res = 0;
      bool sign = true;
      int i = 0;
      
       while(i < s.length() && (s[i] == ' ')){
            i++;
        }
             
        // while(i < s.length() && (s[i] == '0')){
        //     i++;
        // }
              
        if( s[i] == '-'){
            sign = false;
            i++;
        }
        else{
            if(s[i]=='+'){
                sign = true;
                i++;
            }
        }
        while(i < s.length() && ((s[i]-'0')>=0 && (s[i]-'0')<=9 )){
           
            
            if(sign == true && ((s[i]-'0')+10*res)>=INT_MAX){
                return INT_MAX;
            }
           if(sign == false && -((s[i]-'0')+10*res)<=INT_MIN){
                return INT_MIN;
            }
            else{
              
             res = (s[i]-'0')+10*res;
            }
           
            i++;
        }
        if(sign == false){
            return -res;
        }
        return res;
    }
};