// Link: https://leetcode.com/problems/arranging-coins

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: arranging-coins
 *  RUNTIME: 10 ms
 *  MEMORY: 5.9 MB
 *  DATE: 3-7-2023, 10:49:34 AM
 *
 */

// Solution:

class Solution {
public:
    int arrangeCoins(int n) {
        int rowCoins = 1, steps = 0;
        while(n >= rowCoins) {
            n -= rowCoins++;
            steps++;
        }
        return steps;
    }
};
