class Solution {
public:
    vector<string>ans;
    void fun(string s,int n){
        if (s.size() == n) {
            ans.push_back(s);
            return;
        }

        if(s.empty() || s.back() == '1')
        {s.push_back('0');
        fun(s, n);
        s.pop_back();}

        s.push_back('1');
        fun(s, n);
        s.pop_back();
        
    }
    vector<string> validStrings(int n) {
        
        fun("",n);
        
        return ans;
        
    }
};