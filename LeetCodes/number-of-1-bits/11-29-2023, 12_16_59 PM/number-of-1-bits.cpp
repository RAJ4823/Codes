// Link: https://leetcode.com/problems/number-of-1-bits

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-1-bits
 *  RUNTIME: 0 ms
 *  MEMORY: 6.4 MB
 *  DATE: 11-29-2023, 12:16:59 PM
 *
 */

// Solution:

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};
