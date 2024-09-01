// Link: https://leetcode.com/problems/sum-of-all-subset-xor-totals

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sum-of-all-subset-xor-totals
 *  RUNTIME: 0 ms
 *  MEMORY: 40.1 MB
 *  DATE: 5-20-2024, 10:21:28 AM
 *
 */

// Solution:

class Solution {
    public int subsetXORSum(int[] nums) {
        return helper(nums, 0, 0); // nums, level, current XOR
    }
    public int helper(int nums[], int level, int currentXOR){
        if(level == nums.length) return currentXOR;
        int include = helper(nums, level + 1, currentXOR^nums[level]);
        int exclude = helper(nums, level + 1, currentXOR);
        
        return include + exclude;
    }
}
