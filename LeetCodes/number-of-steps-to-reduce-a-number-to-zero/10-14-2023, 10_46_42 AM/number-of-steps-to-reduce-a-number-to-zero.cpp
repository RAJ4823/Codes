// Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-steps-to-reduce-a-number-to-zero
 *  RUNTIME: 3 ms
 *  MEMORY: 6.5 MB
 *  DATE: 10-14-2023, 10:46:42 AM
 *
 */

// Solution:

class Solution {
public:
    int numberOfSteps(int num) {
        long long steps = 0;
        while(num > 0) {
            if(num & 1) {
                num--;
            } else {
                num >>= 1;
            }
            steps++;
        }
        return steps;
    }
};
