class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.size();
        int n2 = needle.size();
        int c=0;
        for(int i=0;i<=n1;i++){
            if( c  == n2){
                return i - c;
            }
           
            else if(needle[c] == haystack[i] && i<n1 ){
               c++;
             }
            
            else{
                if(c!=0){
                   i = i-c;
                   c=0;
                }
            }
            
        }
        return -1;
    }
};
