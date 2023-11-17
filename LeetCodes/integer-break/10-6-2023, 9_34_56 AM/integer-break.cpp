// Link: https://leetcode.com/problems/integer-break

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: integer-break
 *  RUNTIME: 0 ms
 *  MEMORY: 6.5 MB
 *  DATE: 10-6-2023, 9:34:56 AM
 *
 */

// Solution:

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        int div = n / 3, rem = n % 3;
        if (rem == 0) return pow(3, div);
        if (rem == 1) return pow(3, div - 1) * 4;
        return pow(3, div) * 2;
    }
};
