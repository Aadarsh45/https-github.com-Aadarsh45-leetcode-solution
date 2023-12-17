class Solution {
public:
   
    int maxSubarrayLength(vector<int>& v, int k) {
        int n = v.size(), cnt = 0, ans = 0, start = 0, end = 0;
        unordered_map<int, int> mp;
        while(end < n) {
            mp[v[end++]] += 1;
            while(mp[v[end - 1]] > k) {
                mp[v[start++]] -= 1;
            }
            ans = max(ans, end - start);
        }
        return ans;
        
    }
};


        