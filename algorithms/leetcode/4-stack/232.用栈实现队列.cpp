/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include <stack>

class MyQueue {
private:
    std::stack<int> s1, s2;

public:
    MyQueue() {}

    /**
     * 添加元素到队尾
     */
    void push(int x) {
        s1.push(x);
    }

    /**
     * 删除队头的元素并返回
     */
    int pop() {
        // 先调用 peek 保证 s2 非空
        peek();
        int top = s2.top();
        s2.pop();
        return top;
    }

    /**
     * 返回队头元素
     */
    int peek() {
        if (s2.empty()) {
            // 把 s1 元素压入 s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    /**
     * 判断队列是否为空
     */
    bool empty() {
        return s1.empty() && s2.empty();
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

