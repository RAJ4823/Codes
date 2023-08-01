// Link: https://leetcode.com/problems/count-distinct-numbers-on-board

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-distinct-numbers-on-board
 *  RUNTIME: 0 ms
 *  MEMORY: 5.9 MB
 *  DATE: 1-29-2023, 8:02:49 AM
 *
 */

// Solution:

class Solution {
public:
    int distinctIntegers(int n) {
        if(n == 1) return 1;
        return n-1;
    }
};
