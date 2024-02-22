class Solution {
public:
    string lastNonEmptyString(string s) {
        int n = s.size(), maxi = 0;
        unordered_map<char, int> mp;
        for(auto it : s){
            mp[it]++;
            maxi = max(maxi, mp[it]);
        }
        string ans = "";
        for(int i = n - 1 ; i >= 0 ; i--){
            if(mp[s[i]] == maxi){
                ans = s[i] + ans;
                mp.erase(s[i]);
            }
        }
        return ans;
    }
};