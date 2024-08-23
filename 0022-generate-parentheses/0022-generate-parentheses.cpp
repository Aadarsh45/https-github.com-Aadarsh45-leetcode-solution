class Solution {
public:
      void help(int left,int right,int n,string s,vector<string>&ans){
        if(left > n) return;
        if(left == n && right == n){
            ans.push_back(s);
            return;
        }
        if(left < n){
            help(left+1,right,n,s+"(",ans);
        }
        if(right < left){
            help(left,right+1,n,s+")",ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        help(0,0,n,"",ans);
        return ans;
    }
};