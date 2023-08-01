// Link: https://leetcode.com/problems/reach-a-number

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reach-a-number
 *  RUNTIME: 4 ms
 *  MEMORY: 5.9 MB
 *  DATE: 12-30-2022, 11:22:45 AM
 *
 */

// Solution:

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int val = 0;
        while(target > 0) {
            val++;
            target -= val;
        }
        if(target % 2)
            val = (val+1) + (val%2);
        return val;
    }
};
