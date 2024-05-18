// Link: https://leetcode.com/problems/find-the-pivot-integer

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-pivot-integer
 *  RUNTIME: 1 ms
 *  MEMORY: 40.5 MB
 *  DATE: 3-14-2024, 12:37:55 PM
 *
 */

// Solution:

class Solution {
    public int pivotInteger(int n) {
        int totalSum = n * (n + 1) / 2;
        int leftSum = 0, rightSum = 0;
        for(int i=1; i<=n; i++) {
            leftSum += i;
            rightSum = totalSum - (i * (i - 1) / 2);
            if(leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
}
