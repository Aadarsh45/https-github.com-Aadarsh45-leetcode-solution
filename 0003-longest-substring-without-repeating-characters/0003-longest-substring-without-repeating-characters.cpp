class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        if(s.length()==0){
            return 0;
        }
        unordered_map<char,int>map;
        int result=INT_MIN;
       
        
        int i=0;
        for(int k=0;k<size;k++){
            if(map.find(s[k])!=map.end()){
                if(map[s[k]]>=i){
                   i=map[s[k]]+1;
                }
                map[s[k]]=k;
            }
            else{
                 map.insert({s[k],k});
             }
            
           
            result = (result >(k - i + 1))? result: (k - i + 1);  
             
            }
        
           return result; 
   }
        
};