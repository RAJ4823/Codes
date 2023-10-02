// Link: https://leetcode.com/problems/reverse-words-in-a-string-iii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reverse-words-in-a-string-iii
 *  RUNTIME: 18 ms
 *  MEMORY: 11.7 MB
 *  DATE: 9-16-2023, 2:53:37 PM
 *
 */

// Solution:

class Solution {
public:
    string reverseWords(string s) {
        string str = "", ans = "";
        for(auto &ch: s) {
            if(ch == ' ') {
                reverse(str.begin(), str.end());
                ans += str;
                ans += " ";
                str = "";
            } else {
                str += ch;
            }
        }
        if(str.length() > 0) {
            reverse(str.begin(), str.end());
            ans += str;
        }
        return ans;
    }
};
