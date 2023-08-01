// Link: https://leetcode.com/problems/maximum-69-number

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-69-number
 *  RUNTIME: 0 ms
 *  MEMORY: 5.9 MB
 *  DATE: 2-8-2023, 11:06:26 AM
 *
 */

// Solution:

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for (auto &currChar : s) {
            if (currChar == '6') {
                currChar = '9';
                break;
            }
        }
        return stoi(s);
    }
};
