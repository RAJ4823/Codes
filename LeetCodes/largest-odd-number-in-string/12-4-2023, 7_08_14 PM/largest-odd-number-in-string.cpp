// Link: https://leetcode.com/problems/largest-odd-number-in-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: largest-odd-number-in-string
 *  RUNTIME: 31 ms
 *  MEMORY: 15.4 MB
 *  DATE: 12-4-2023, 7:08:14 PM
 *
 */

// Solution:

class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.size() - 1; i>=0; i--) {
            if((num[i] - '0') % 2) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
