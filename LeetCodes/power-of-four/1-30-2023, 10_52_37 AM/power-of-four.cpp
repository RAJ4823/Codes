// Link: https://leetcode.com/problems/power-of-four

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: power-of-four
 *  RUNTIME: 0 ms
 *  MEMORY: 6.1 MB
 *  DATE: 1-30-2023, 10:52:37 AM
 *
 */

// Solution:

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;

        if(log2(n) == (int)(log2(n))) {
            int val = log2(n);
            if(val % 2 == 0)
                    return true;
        } 
        return false;
    }
};
