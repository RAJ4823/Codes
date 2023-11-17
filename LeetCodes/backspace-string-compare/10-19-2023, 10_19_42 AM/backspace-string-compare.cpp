// Link: https://leetcode.com/problems/backspace-string-compare

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: backspace-string-compare
 *  RUNTIME: 3 ms
 *  MEMORY: 6.8 MB
 *  DATE: 10-19-2023, 10:19:42 AM
 *
 */

// Solution:

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str1 = "", str2 = "";
        for(auto &ch: s) {
            if(ch == '#') {
                if(str1.size() > 0) 
                    str1.pop_back();
            } else {
                str1 += ch;
            }
        }
        for(auto &ch: t) {
            if(ch == '#') {
                if(str2.size() > 0) 
                    str2.pop_back();
            } else {
                str2 += ch;
            }
        }
        return str1 == str2;
    }
};
