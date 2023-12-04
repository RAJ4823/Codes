// Link: https://leetcode.com/problems/largest-odd-number-in-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: largest-odd-number-in-string
 *  RUNTIME: 22 ms
 *  MEMORY: 15.3 MB
 *  DATE: 12-4-2023, 7:08:59 PM
 *
 */

// Solution:

class Solution {
public:
    string largestOddNumber(string n) {
        return n.substr(0, n.find_last_of("13579") + 1);
    }
};
