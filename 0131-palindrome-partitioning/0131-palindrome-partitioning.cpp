class Solution {
public:
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void help(int i,string &s,vector<string> &current,vector<vector<string>>&res){
        //base case
        if(i >= s.length()){
            res.push_back(current);
            return;
        }


        //operation
        for(int j = i;j<s.length();j++){
            if(isPalindrome(s,i,j)){
                current.push_back(s.substr(i,j-i+1));
                help(j+1,s,current,res);
                current.pop_back();
            }

        }

    }

   

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> current;
        help(0, s, current, res);
        return res;
    }
};
