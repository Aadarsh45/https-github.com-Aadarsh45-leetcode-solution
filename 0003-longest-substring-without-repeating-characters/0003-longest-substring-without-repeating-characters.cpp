class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int lo = 0;
        int cnt = 0;
        int i = 0;

        for(i = 0;i<s.length();i++){
            if(mp.find(s[i])!= mp.end()){
                lo = max(lo, mp[s[i]] + 1);
            }
             mp[s[i]] = i;
            cnt = max(cnt, i - lo + 1);
        }

        return cnt;
        
    }
};