class Solution {
public:
    bool answer = false;
    void divisor(int n,bool answer){
        if(n == 0){
            return;
        }
        int x = n/2;
        if(x%2 == 0){
            if( answer == true){
                answer = false;
            }
            else{
                answer = true;
            }
        }
        else{
            if( answer == true){
                answer = false;
            }
            else{
                answer = true;
            }
            
        }
        
    }
    bool divisorGame(int n) {
   if(n%2 != 0){
       answer = true;
       
   }
        divisor(n,answer);
        
        return !answer;
        
    }
};