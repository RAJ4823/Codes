// Link: https://leetcode.com/problems/n-th-tribonacci-number

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: n-th-tribonacci-number
 *  RUNTIME: 0 ms
 *  MEMORY: 6 MB
 *  DATE: 1-30-2023, 10:34:59 AM
 *
 */

// Solution:

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;

        int prev3 = 0, prev2 = 1, prev1 = 1, curr;
        for(int i = 3; i <= n; i++) {
            curr = prev3 + prev2 + prev1;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};
