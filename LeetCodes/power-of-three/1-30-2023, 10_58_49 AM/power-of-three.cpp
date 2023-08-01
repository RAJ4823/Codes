// Link: https://leetcode.com/problems/power-of-three

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: power-of-three
 *  RUNTIME: 28 ms
 *  MEMORY: 6 MB
 *  DATE: 1-30-2023, 10:58:49 AM
 *
 */

// Solution:

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        return (1162261467 % n == 0);
    }
};
