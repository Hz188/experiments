/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <queue>
using namespace std;
class MyStack {
    queue<int> q1;
    queue<int> q2;

public:
    /**
     * 添加元素到栈顶
     */
    void push(int x) {
        // x 是队列的队尾，是栈的栈顶
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    /**
     * 返回栈顶元素
     */
    int top() {
        return q1.front();
    }

    /**
     * 删除栈顶的元素并返回
     */
    int pop() {
        int temp = q1.front();
        q1.pop();
        return temp;
    }

    /**
     * 判断栈是否为空
     */
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

