// Link: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-changes-to-make-alternating-binary-string
 *  RUNTIME: 3 ms
 *  MEMORY: 7.2 MB
 *  DATE: 12-24-2023, 5:30:56 PM
 *
 */

// Solution:

class Solution {
public:
    int minOperations(string s) {
        int op1 = 0, op2 = 0;
        char ch1 = '0', ch2 = '1';
        for(auto &c: s) {
            op1 += (c == ch1);
            op2 += (c == ch2);
            swap(ch1, ch2);
        }
        return min(op1, op2);
    }
};
