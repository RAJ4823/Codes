// Link: https://leetcode.com/problems/number-of-zero-filled-subarrays

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-zero-filled-subarrays
 *  RUNTIME: 170 ms
 *  MEMORY: 107.6 MB
 *  DATE: 3-21-2023, 8:29:57 AM
 *
 */

// Solution:

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0, cont = 0;
        for(auto &val: nums) {
            if(val == 0) {
                cont++;
            } else {
                count += (cont*(cont+1))/2;
                cont = 0;
            }
        }
        count += (cont*(cont+1))/2;
        return count;
    }
};
