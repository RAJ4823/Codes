// Link: https://leetcode.com/problems/implement-stack-using-queues

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: implement-stack-using-queues
 *  RUNTIME: 0 ms
 *  MEMORY: 7 MB
 *  DATE: 8-28-2023, 9:29:57 AM
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
