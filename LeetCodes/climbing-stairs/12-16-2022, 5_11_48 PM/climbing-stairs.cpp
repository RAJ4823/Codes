// Link: https://leetcode.com/problems/climbing-stairs

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: climbing-stairs
 *  RUNTIME: 3 ms
 *  MEMORY: 6 MB
 *  DATE: 12-16-2022, 5:11:48 PM
 *
 */

// Solution:

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int prev2 = 1;
        int prev1 = 1;
        int curr = 0;
        for(int i=2; i<=n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
