class MinStack {
    stack<int> st, mn;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(!mn.empty()){
            mn.push(min(mn.top(), val));
            return;
        };
        mn.push(val);
    }
    
    void pop() {
        st.pop();
        mn.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mn.top();
    }
};
