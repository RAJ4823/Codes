// Link: https://leetcode.com/problems/implement-stack-using-queues

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: implement-stack-using-queues
 *  RUNTIME: 0 ms
 *  MEMORY: 7 MB
 *  DATE: 12-16-2022, 5:00:44 PM
 *
 */

// Solution:

class MyStack {
public:
    MyStack() {}
    queue<int> q, temp;
    
    void push(int x) {
        q.push(x);
        int len = q.size()-1;
        while(len--) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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
