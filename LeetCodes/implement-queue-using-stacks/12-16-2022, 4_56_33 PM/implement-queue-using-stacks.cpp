// Link: https://leetcode.com/problems/implement-queue-using-stacks

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: implement-queue-using-stacks
 *  RUNTIME: 0 ms
 *  MEMORY: 6.9 MB
 *  DATE: 12-16-2022, 4:56:33 PM
 *
 */

// Solution:

class MyQueue {
public:
    MyQueue() { }

    stack<int> s, temp;
    
    void push(int x) {
        while(!s.empty()) {
            temp.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
    }
    
    int pop() {
        int x = s.top();
        s.pop();
        return x;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
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
