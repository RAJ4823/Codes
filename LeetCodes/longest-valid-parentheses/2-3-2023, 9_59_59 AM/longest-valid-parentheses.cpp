// Link: https://leetcode.com/problems/longest-valid-parentheses

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-valid-parentheses
 *  RUNTIME: 2 ms
 *  MEMORY: 7.4 MB
 *  DATE: 2-3-2023, 9:59:59 AM
 *
 */

// Solution:

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxlen = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    maxlen = max(maxlen, i - st.top());
                }
            }
        }
        return maxlen;
    }
};
