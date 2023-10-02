// Link: https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sum-of-values-at-indices-with-k-set-bits
 *  RUNTIME: 8 ms
 *  MEMORY: 21.9 MB
 *  DATE: 9-18-2023, 6:25:38 PM
 *
 */

// Solution:

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            if(__builtin_popcount(i) == k) {
                sum += nums[i];
            }
        }
        return sum;
    }
};
