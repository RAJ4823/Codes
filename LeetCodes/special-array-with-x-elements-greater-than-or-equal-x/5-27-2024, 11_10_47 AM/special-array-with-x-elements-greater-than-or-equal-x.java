// Link: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: special-array-with-x-elements-greater-than-or-equal-x
 *  RUNTIME: 1 ms
 *  MEMORY: 41.6 MB
 *  DATE: 5-27-2024, 11:10:47 AM
 *
 */

// Solution:


class Solution {
    public int specialArray(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= (n - i)) {
                if (i == 0 || nums[i - 1] < (n - i)) {
                    return n - i;
                }
            }
        }
        return -1;
    }
}
