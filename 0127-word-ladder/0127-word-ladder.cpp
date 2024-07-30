class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         queue<pair<string, int>> q;

       
        q.push({beginWord, 1});

        unordered_set<string> mp(wordList.begin(), wordList.end());
        mp.erase(beginWord);
        
        while(!q.empty()){
            auto[word,cnt]  = q.front();
            q.pop();
            
            if(word == endWord){
                return cnt;
            }
            
            for(int i = 0;i<word.length();i++){
               char original = word[i];
                for(int j = 0;j<26;j++){
                    word[i] = char('a'+j);
                    
                    if(mp.find(word) != mp.end()){
                        mp.erase(word);
                        q.push({word,cnt+1});
                    }
                }
                word[i] = original;
                
                
                
            }
        }
        
        
        return 0;
    }
};