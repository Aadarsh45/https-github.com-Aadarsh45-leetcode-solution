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
//          for(int i=0;i<n;i++){
//             if(st.size()==0 || sameParity(st.top(),v[i]) || (st.top()<0 && v[i]>0)){
//                 st.push(v[i]); // no collision
//             }
//              else{
//                 while(st.size()>0 && st.top()>0 && st.top() < abs(v[i])) st.pop(); // currect asteroid destroying existing
                
//                 if(st.size()==0 || st.top()<0){
//                     st.push(v[i]);
//                 }else if(st.top() == abs(v[i])){
//                     st.pop();  // both asteroids get destroyed
//                 }
//             }
//         }
        
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