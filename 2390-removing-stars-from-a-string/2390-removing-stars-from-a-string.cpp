class Solution {
public:
    string removeStars(string s) {
       
        stack < char> stack;
        int cnt = 0;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == '*'){
                stack.pop();
                    cnt--;
            }
            else{
                cnt++;
                stack.push(s[i]);
            }
        }
        string ans;
        for(int i=cnt-1;i>=0;i--){
            ans +=stack.top();
            stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};