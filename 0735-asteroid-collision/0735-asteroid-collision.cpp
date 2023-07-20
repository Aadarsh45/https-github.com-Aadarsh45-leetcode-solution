class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>stk;
        
        
        for(int i = 0;i<asteroids.size();i++){
            if(stk.empty()){
                stk.push(asteroids[i]);
                
            }
            else if(asteroids[i]<0 && stk.top()>0){
                
               while(!stk.empty() && stk.top()>0 &&abs(stk.top())<abs(asteroids[i])){
                    stk.pop();
                }
                 if(stk.size()==0 || stk.top()<0){
                    stk.push(asteroids[i]);
                }else if(stk.top() == abs(asteroids[i])){
                    stk.pop();  // both asteroids get destroyed
                }
            }
            else{
               stk.push(asteroids[i]);
            }
        }

        vector<int>vec;
        
        if(stk.empty()){
            return vec;
        }
        
        while(!stk.empty()){
            vec.push_back(stk.top());
            stk.pop();
        }
        
        reverse(vec.begin(),vec.end());
        
        return vec;
        
    }
};