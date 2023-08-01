// Link: https://leetcode.com/problems/power-of-two

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: power-of-two
 *  RUNTIME: 3 ms
 *  MEMORY: 6 MB
 *  DATE: 1-30-2023, 10:53:54 AM
 *
 */

// Solution:

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        if(log2(n) == (int)log2(n))
            return true;
        return false;
    }
};
