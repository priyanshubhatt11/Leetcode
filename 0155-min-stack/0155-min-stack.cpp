class MinStack {
public:
    
    stack<long long> st;
    long long mi = 1e10;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(mi == 1e10){
            st.push(val);
            mi = val;
        }
        else{
            if(mi <= val){
                st.push(val);
            }
            else{
                st.push(2*1LL*val - mi);
                mi = val;
            }
        }
    }
    
    void pop() {
        if(st.size() == 1)mi = 1e10;
        else if(st.top() < mi){
            mi = 2*mi - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < mi)return mi;
        return st.top();
    }
    
    int getMin() {
        return mi;
    }
};
