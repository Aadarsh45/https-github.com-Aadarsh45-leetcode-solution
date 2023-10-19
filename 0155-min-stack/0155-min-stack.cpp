class MinStack {
public:
    stack<int> arr , min_arr ;

    MinStack() {
        
    }
    
    void push(int val) {
        arr.push(val) ;
        if(!min_arr.empty()){
            val = min (val , min_arr.top()) ; 
        }

        min_arr.push(val) ;  
    }
    
    void pop() {
        arr.pop() ;
        min_arr.pop() ;
    }
    
    int top() {
        return arr.top() ;
    }
    
    int getMin() {
        return min_arr.top() ;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */