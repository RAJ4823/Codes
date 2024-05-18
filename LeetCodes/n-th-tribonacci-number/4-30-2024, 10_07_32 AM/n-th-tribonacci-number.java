// Link: https://leetcode.com/problems/n-th-tribonacci-number

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: n-th-tribonacci-number
 *  RUNTIME: 0 ms
 *  MEMORY: 40.1 MB
 *  DATE: 4-30-2024, 10:07:32 AM
 *
 */

// Solution:

class Solution {
    public int tribonacci(int n) {
        if(n < 2) return n;
        int a = 0, b = 1, c = 1;

        for(int i=3; i<=n; i++) {
            int res = a + b + c;
            a = b;
            b = c;
            c = res;
        }
        return c;
    }
}
