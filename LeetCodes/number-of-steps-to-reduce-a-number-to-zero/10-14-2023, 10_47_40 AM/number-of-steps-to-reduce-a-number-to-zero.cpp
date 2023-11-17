// Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-steps-to-reduce-a-number-to-zero
 *  RUNTIME: 0 ms
 *  MEMORY: 6.3 MB
 *  DATE: 10-14-2023, 10:47:40 AM
 *
 */

// Solution:

class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0) return 0;
        return log2(num) + __builtin_popcount(num);
    }
};
