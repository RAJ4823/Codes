// Link: https://leetcode.com/problems/valid-parentheses

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: valid-parentheses
 *  RUNTIME: 4 ms
 *  MEMORY: 6.4 MB
 *  DATE: 4-10-2023, 6:18:33 PM
 *
 */

// Solution:

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, int> val({
            {'(', 1}, {'{', 2}, {'[', 3}, 
            {')', -1}, {'}', -2}, {']', -3}
        });
        for(auto &p: s) {
            if(val[p] > 0) st.push(p);
            else {
                if(!st.empty() && val[st.top()] == abs(val[p]))
                    st.pop();
                else
                    return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
