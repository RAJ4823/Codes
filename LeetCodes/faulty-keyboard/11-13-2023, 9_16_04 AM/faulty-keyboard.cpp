// Link: https://leetcode.com/problems/faulty-keyboard

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: faulty-keyboard
 *  RUNTIME: 9 ms
 *  MEMORY: 6.9 MB
 *  DATE: 11-13-2023, 9:16:04 AM
 *
 */

// Solution:

class Solution {
public:
    string finalString(string s) {
        string ans = "";
        for(auto &ch: s) {
            if(ch == 'i') {
                reverse(ans.begin(), ans.end());
            } else {
                ans += ch;
            }
        }
        return ans;
    }
};
