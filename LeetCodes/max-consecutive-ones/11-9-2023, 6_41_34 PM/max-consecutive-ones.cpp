// Link: https://leetcode.com/problems/max-consecutive-ones

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: max-consecutive-ones
 *  RUNTIME: 28 ms
 *  MEMORY: 36.3 MB
 *  DATE: 11-9-2023, 6:41:34 PM
 *
 */

// Solution:

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxi = 0;
        for(auto &val: nums) {
            if(val) {
                count++;
            } else {
                maxi = max(maxi, count);
                count = 0;
            }
        }
        return max(maxi, count);
    }
};
