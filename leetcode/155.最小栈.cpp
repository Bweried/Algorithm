#include<iostream>
#include<stack>
using namespace std;

class MinStack {
    stack<pair<int, int>> st;

public:
    MinStack() {
        // 添加栈底哨兵 INT_MAX
        st.emplace(0, INT_MAX);
    }
    
    void push(int val) {
        st.emplace(val, min(getMin(), val));
    }
    
    void pop() {
        st.pop();
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