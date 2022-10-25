/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <stack>
using namespace std;

// @lc code=start
class MyQueue {
private:
    /**
     * 一个输入栈，一个输出栈
     * 输出时如果输出栈为空，就将输入栈中的内容压入输出栈,实现先进先出
     */
    stack<int> inStack, outStack;

    // 将输入栈的内容压入输出栈
    void in2out() {
        while (!inStack.empty()) {
            outStack.emplace(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inStack.emplace(x);
    }

    int pop() {
        if (outStack.empty()) {
            in2out();
        }
        int t = outStack.top();
        outStack.pop();
        return t;
    }

    int peek() {
        if (outStack.empty()) {
            in2out();
        }
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
