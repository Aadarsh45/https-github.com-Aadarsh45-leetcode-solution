class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> cnt(n+1);
        int person;
        
          for(auto person : trust){
              cnt[person[0]]--;
              cnt[person[1]]++;
              
          }
        
        for(int i=1;i<=n;i++){
            if(cnt[i] ==  n-1){
                return i;
            }
        }
        
        
        return -1;
    }
};