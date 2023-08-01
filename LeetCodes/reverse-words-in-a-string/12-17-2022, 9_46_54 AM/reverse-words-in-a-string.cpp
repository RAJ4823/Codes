// Link: https://leetcode.com/problems/reverse-words-in-a-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reverse-words-in-a-string
 *  RUNTIME: 2 ms
 *  MEMORY: 7.6 MB
 *  DATE: 12-17-2022, 9:46:54 AM
 *
 */

// Solution:

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.size();
        int i = 0;
        string str;
        while(i < n) {
            while(s[i] == ' ' && i < n)
                i++;
            str = "";
            while(s[i] != ' ' && i < n) {
                str += s[i];
                i++;
            }
            if(str != "")
                st.push(str);
            // cout << str << " ";
        }
        str = "";
        while(!st.empty()) {
            str += st.top();
            st.pop();
            if(!st.empty())
                str += " ";
        }
        return str;
    }
};
