// Link: https://leetcode.com/problems/number-of-1-bits

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-1-bits
 *  RUNTIME: 3 ms
 *  MEMORY: 5.8 MB
 *  DATE: 1-30-2023, 11:03:36 AM
 *
 */

// Solution:

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n) {
            if(n&1) count++;
            n = (n >> 1);
        }
        return count;
    }
};
