// Link: https://leetcode.com/problems/smallest-even-multiple

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: smallest-even-multiple
 *  RUNTIME: 3 ms
 *  MEMORY: 6.5 MB
 *  DATE: 9-18-2023, 6:58:27 PM
 *
 */

// Solution:

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n << (n & 1);
    }
};
