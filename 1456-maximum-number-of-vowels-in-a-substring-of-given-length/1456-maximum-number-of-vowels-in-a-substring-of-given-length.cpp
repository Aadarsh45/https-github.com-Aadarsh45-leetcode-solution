class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt = 0;
        int ans = 0;
        int lo=0;
        int hgh = 0;
        
        while(hgh < s.size()){
            if(ans == k){
                break;
            }
            if(hgh-lo >= k){
                if(s[lo] == 'a' || s[lo] == 'e' || s[lo] == 'i' || s[lo] == 'o' ||s[lo] == 'u' ){
                    cnt --;
                    lo++;
                    
                }
                else{
                    lo++;
                    
                }
                continue;
            }
            if(s[hgh] == 'a' || s[hgh] == 'e' || s[hgh] == 'i' || s[hgh] == 'o' ||s[hgh] == 'u'){
               
                cnt++;
            }
             hgh++;
            
            ans=max(ans,cnt);
            
            
        }
        return ans;
        
    }
};