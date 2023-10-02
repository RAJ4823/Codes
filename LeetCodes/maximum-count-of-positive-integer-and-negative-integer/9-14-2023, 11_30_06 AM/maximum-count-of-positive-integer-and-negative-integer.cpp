// Link: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-count-of-positive-integer-and-negative-integer
 *  RUNTIME: 12 ms
 *  MEMORY: 17.9 MB
 *  DATE: 9-14-2023, 11:30:06 AM
 *
 */

// Solution:

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negCount = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int posCount = nums.size() - (upper_bound(nums.begin(), nums.end(), 0) - nums.begin());
        return max(negCount, posCount);
    }
};
