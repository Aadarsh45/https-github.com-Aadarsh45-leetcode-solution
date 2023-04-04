class Solution {
public:
    int partitionString(string s) {
        
        int cnt = 0, substringStart=0;
        vector<int> lastSeen(26,-1);
        
        
       
        for (int i=0; i<s.size(); i++){
            if(lastSeen[s[i]-'a'] >= substringStart){
                cnt++;
                substringStart = i;
            }
            
            lastSeen[s[i]- 'a'] = i;
            
            
        }
        return cnt+1;
        
    }
};