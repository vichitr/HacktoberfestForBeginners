#include<stack>
#include<iostream>
using namespace std;

class MinStack {
public:
    MinStack() {
        st = stack<pair<int, int>>();
    }

    void push(int val) {
        if (st.empty()) {
            st.push({ val,val });
        }
        else {
            st.push({ val,min(val,st.top().second) });
        }
    }

    void pop() {
        if (st.size()) { st.pop(); }
    }

    int top() {
        if (st.size()) {
            return st.top().first;
        }
        return -1;
    }

    int getMin() {
        if (st.size()) {
            return st.top().second;
        }
        return -1;
    }
private:
    stack<pair<int, int>> st;

};