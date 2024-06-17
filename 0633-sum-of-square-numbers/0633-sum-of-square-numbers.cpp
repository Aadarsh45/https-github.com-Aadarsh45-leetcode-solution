class Solution {
public:
    bool judgeSquareSum(int c) {
        int lo = 0;
        int hgh = sqrt(c);
        
        while(lo <= hgh){
            int mid = lo+(hgh-lo)/2;
            long long temp = 1ll*lo*lo + 1ll*hgh*hgh;
            if(temp == c){
                return true;
            }
            else if(temp < c){
                lo++;
            }
            else{
                hgh--;
            }
            
            
        }
        return false;
        
    }
};