class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    int m=INT_MAX;
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
            m=val;
        }else{
            m=min(st.top().second,val);
            st.push({val,m});
        }
    }
    
    void pop() {
        st.pop();
        if(!st.empty())
        m=st.top().second;
        else m=INT_MAX;
    }
    
    int top() {
        return st.top().first;
        
    }
    
    int getMin() {
        return st.top().second;
        
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