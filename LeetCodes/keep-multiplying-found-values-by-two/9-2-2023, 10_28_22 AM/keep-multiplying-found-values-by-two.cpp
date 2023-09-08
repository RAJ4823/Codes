// Link: https://leetcode.com/problems/keep-multiplying-found-values-by-two

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: keep-multiplying-found-values-by-two
 *  RUNTIME: 4 ms
 *  MEMORY: 10.6 MB
 *  DATE: 9-2-2023, 10:28:22 AM
 *
 */

// Solution:

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int mask = 0, bit = 0;
        for(auto &val: nums) {
           if(val % original == 0) {
                bit = val / original;
                if (!(bit & (bit - 1))) {
                    mask |= bit;
                }
           }
        }
        int mul = ((mask + 1) & (~mask));
        return original * mul;
    }
};
