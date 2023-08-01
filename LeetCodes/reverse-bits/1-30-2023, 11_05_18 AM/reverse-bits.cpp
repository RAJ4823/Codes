// Link: https://leetcode.com/problems/reverse-bits

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reverse-bits
 *  RUNTIME: 3 ms
 *  MEMORY: 6 MB
 *  DATE: 1-30-2023, 11:05:18 AM
 *
 */

// Solution:

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        for (int i = 0; i < 32; i++, n >>= 1) {
            m <<= 1;
            m |= n & 1;
        }
        return m;
    }
};
