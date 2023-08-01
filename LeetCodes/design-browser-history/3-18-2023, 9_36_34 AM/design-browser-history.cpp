// Link: https://leetcode.com/problems/design-browser-history

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: design-browser-history
 *  RUNTIME: 127 ms
 *  MEMORY: 57.4 MB
 *  DATE: 3-18-2023, 9:36:34 AM
 *
 */

// Solution:

class BrowserHistory {
public:
    vector<string> history;
    int index = 0;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }
    
    void visit(string url) {
        index++;
        history.resize(index);
        history.push_back(url);
    }
    
    string back(int steps) {
        index = max(0, index - steps);
        return history[index];
    }
    
    string forward(int steps) {
        index = min((int)history.size() - 1, index + steps);
        return history[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
