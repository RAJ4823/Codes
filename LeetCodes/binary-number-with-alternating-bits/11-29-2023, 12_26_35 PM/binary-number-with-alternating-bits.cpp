// Link: https://leetcode.com/problems/binary-number-with-alternating-bits

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: binary-number-with-alternating-bits
 *  RUNTIME: 0 ms
 *  MEMORY: 6.3 MB
 *  DATE: 11-29-2023, 12:26:35 PM
 *
 */

// Solution:

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x = (n ^ (n >> 2));
        return !(x & (x - 1));
    }
};
