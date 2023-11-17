// Link: https://leetcode.com/problems/power-of-four

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: power-of-four
 *  RUNTIME: 0 ms
 *  MEMORY: 6.6 MB
 *  DATE: 10-23-2023, 10:38:34 AM
 *
 */

// Solution:

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        return fmod((double)(log(n) / log(4)), 1.0) == 0;
    }
};
