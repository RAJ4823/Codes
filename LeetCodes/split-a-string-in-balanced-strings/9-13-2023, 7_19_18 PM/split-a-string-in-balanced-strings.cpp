// Link: https://leetcode.com/problems/split-a-string-in-balanced-strings

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: split-a-string-in-balanced-strings
 *  RUNTIME: 0 ms
 *  MEMORY: 6.7 MB
 *  DATE: 9-13-2023, 7:19:18 PM
 *
 */

// Solution:

class Solution {
public:
    int balancedStringSplit(string s) {
        stack<char> st;
        int count = 0;
        for(auto &ch: s) {
            if(st.empty()) count++;
            if(st.empty() || st.top() == ch) {
                st.push(ch);
            } else {
                st.pop();
            }
        }
        return count;
    }
};
