// Link: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-flips-to-make-a-or-b-equal-to-c
 *  RUNTIME: 0 ms
 *  MEMORY: 5.8 MB
 *  DATE: 6-7-2023, 9:10:42 AM
 *
 */

// Solution:

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while(a || b || c) {
            if(((a & 1) | (b & 1)) != (c & 1)) {
                flips += ((a & 1) + (b & 1) + (c & 1));
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return flips;
    }
};
