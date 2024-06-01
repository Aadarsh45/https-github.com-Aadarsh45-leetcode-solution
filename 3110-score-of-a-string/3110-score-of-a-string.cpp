class Solution {
public:
    int scoreOfString(string s) {
        int n = s.length();
        vector<int> v(n,0);
        for(int i = 0;i<n;i++){
            v[i] = int(s[i]);
            cout<<v[i]<<endl;
        }
        int ans = 0;
        for(int i =0;i<n-1;i++){
            ans += abs(v[i] - v[i+1]);
        }
        return ans;
        
    }
};