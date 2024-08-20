class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        

        for(int i =0 ;i<tokens.size();i++){
            if(tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "-" ||tokens[i] == "/"){
                string op = tokens[i];
                int op1 = stk.top();stk.pop();
                int op2 = stk.top();stk.pop();
                
                if(op == "+"){
                    stk.push(op1+op2);
                }
                else if(op == "-"){
                    stk.push(op2-op1);
                }
                else if(op == "*"){
                     stk.push(op1*op2);
                }
                else{
                    stk.push((op2/op1));
                }
                cout<<stk.top();
            }

            else{
                int temp = stoi(tokens[i]);
                stk.push(temp);
            }
        }
        return stk.top();
        
    }
};