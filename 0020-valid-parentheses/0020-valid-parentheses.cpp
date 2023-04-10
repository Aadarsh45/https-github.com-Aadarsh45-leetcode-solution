class Solution {
public:
    bool isValid(string s) {
        
        stack <char> stack;
        
        for(int i=0; i<s.size(); i++){
          
               
                   if(!stack.empty() && s[i] == ')' && stack.top() == '('){
                       stack.pop();
                   }
                    else if(!stack.empty() && s[i] == '}' && stack.top() == '{'){
                       stack.pop();
                   }
                    else if(!stack.empty() && s[i] == ']' && stack.top() == '['){
                       stack.pop();
                   }
               else{
                 stack.push(s[i]);
               }
          
           
           
        }
        if(stack.empty()){
            return true;
        }
        return false;
    }
};