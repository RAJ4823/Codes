// Link: https://leetcode.com/problems/count-total-number-of-colored-cells

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-total-number-of-colored-cells
 *  RUNTIME: 0 ms
 *  MEMORY: 6.1 MB
 *  DATE: 3-28-2023, 9:25:57 PM
 *
 */

// Solution:

class Solution {
public:
    long long coloredCells(int n) {
        long long N = n;
        long long count = 2 * N * (N-1);
        return count + 1;
    }
};
