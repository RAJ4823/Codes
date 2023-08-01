// Link: https://leetcode.com/problems/fibonacci-number

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: fibonacci-number
 *  RUNTIME: 0 ms
 *  MEMORY: 5.8 MB
 *  DATE: 12-16-2022, 5:14:59 PM
 *
 */

// Solution:

class Solution {
public:
    int fib(int n) {
        if(n < 2) return n;
        int prev2 = 0;
        int prev1 = 1;
        int curr = 0;
        for(int i=2; i<=n; i++)
        {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
