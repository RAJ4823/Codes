// Link: https://leetcode.com/problems/smallest-even-multiple

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: smallest-even-multiple
 *  RUNTIME: 0 ms
 *  MEMORY: 6.3 MB
 *  DATE: 9-18-2023, 6:57:51 PM
 *
 */

// Solution:

class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n & 1) return n << 1;
        return n;
    }
};
