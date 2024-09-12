class Solution {
public:
    bool help(string str,unordered_set<char>&mp){
        for(int j = 0;j<str.length();j++){
                if(mp.find(str[j]) == mp.end()){
                    return false;
                }
        }
        return true;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>mp;
        for(auto it: allowed){
            mp.insert(it);
        }
        int cnt = 0;
        for(int i = 0;i<words.size();i++){
            if(help(words[i],mp)){
                cnt++;
            }
            
        }
        return cnt;
        
    }
};