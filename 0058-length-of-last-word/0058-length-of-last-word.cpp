class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length() == 0){
            return 0;
        }
        int l=size(s)-1;
        int count=0;
      
        while(l>=0&&s[l]==' '){
            l--;
        }
        while(l>=0){
            if(s[l]!=' '){
                count++;
            }else{
                break;
            }
            l--;
        }
        return count;
        
    }
};