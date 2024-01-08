// Link: https://leetcode.com/problems/maximum-product-difference-between-two-pairs

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-product-difference-between-two-pairs
 *  RUNTIME: 23 ms
 *  MEMORY: 20.7 MB
 *  DATE: 12-18-2023, 12:46:44 PM
 *
 */

// Solution:

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return (nums[nums.size() - 1] * nums[nums.size() - 2]) - (nums[0] * nums[1]);
    }
};
