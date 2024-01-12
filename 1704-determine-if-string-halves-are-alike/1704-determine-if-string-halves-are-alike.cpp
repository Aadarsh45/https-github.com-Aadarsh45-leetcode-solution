class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char> vow={'a','e','i','o','u','A','E','I','O','U'};
        int n=s.size()/2, f=0;
        for(int i=0; i<n; i++){
            f+=(vow.count(s[i])-vow.count(s[n+i]));
        }
        return f==0;
    }
};