/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include <climits>
#include <stack>
#include <vector>
using namespace std;

// @lc code=start
class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {
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
// @lc code=end
