// Link: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-odd-numbers-in-an-interval-range
 *  RUNTIME: 3 ms
 *  MEMORY: 6 MB
 *  DATE: 2-13-2023, 8:26:07 AM
 *
 */

// Solution:

class Solution {
public:
    int countOdds(int low, int high) {
        int count = (high - low) / 2;
        if (high % 2 || low % 2) count ++;
        return count;
    }
};
