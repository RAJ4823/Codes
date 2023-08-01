// Link: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-flips-to-make-a-or-b-equal-to-c
 *  RUNTIME: 0 ms
 *  MEMORY: 5.9 MB
 *  DATE: 6-7-2023, 9:08:24 AM
 *
 */

// Solution:

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while(a || b || c) {
            if(((a & 1) | (b & 1)) != (c & 1)) {
                if(c & 1) flips++;
                else flips += ((a & 1) + (b & 1));
            }
            a = a>>1;
            b = b>>1;
            c = c>>1;
        }
        return flips;
    }
};
