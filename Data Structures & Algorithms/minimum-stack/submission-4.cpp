class MinStack {
private:
    long long mini = INT_MAX;
    stack<long long> stk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()) {
            stk.push(val);
            mini = val;
        } else {
            if(mini<=val) stk.push(val);
            else {
                stk.push(2LL*val-mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        if(stk.empty()) return;
        if(stk.top()<mini) {
            // val = mini;
            // newVal = 2*val - prev_mini;
            // stk.top() = 2 * mini - prev_mini
            mini = 2 * mini - stk.top();
        }
        stk.pop();
    }
    
    int top() {
        if(mini<=stk.top()) return stk.top();
        else return mini;
    }
    
    int getMin() {
        return mini;
    }
};
