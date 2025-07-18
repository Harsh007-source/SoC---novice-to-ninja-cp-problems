class MinStack {   
public:
    stack<long long int> s;
    long long int minVal;
    MinStack() {
                             // SC = O(n)
    }
    
    void push(int val) {
        
        if(s.empty()){
            s.push(val);
            minVal = val;
        }else{
            if(val < minVal){
                s.push( (long long)2*val - minVal );
                minVal = val;
            }else{
                s.push(val);
            }
        }
    }
    
    void pop() {
        if(s.top() < minVal){  // i.e. s.top() is val2 = 2*val - minVal
            minVal = 2*minVal - s.top();
        }
        s.pop();
    }
    
    int top() {
        if(s.top() < minVal){  // i.e. s.top() is val2 = 2*val - minVal
            return minVal;
        }else{
            return s.top();
        }
    }
    
    int getMin() {
        return minVal;
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
