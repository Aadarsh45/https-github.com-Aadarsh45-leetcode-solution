class Solution {
public:
    int minimumPushes(string word) {
      int n = word.size();
      
      vector<int>freq(26,0);
      
      for(int i =0;i<n;i++){
        int  temp = word[i] - 'a';
        freq[temp]++;
      }
      
      sort(freq.begin(),freq.end(),greater<int>());
      int s = freq.size();
      
      int cnt = 0;
      int i =0;
      while(i<s){
        cnt+= freq[i]*((i/8) + 1);
        i++;
      }
        return cnt;
    }
};