// Link: https://leetcode.com/problems/first-missing-positive

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: first-missing-positive
 *  RUNTIME: 1 ms
 *  MEMORY: 55 MB
 *  DATE: 3-26-2024, 10:10:05 AM
 *
 */

// Solution:

class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for(int i=0;i<n;i++) {
            if(nums[i] < 0) nums[i] = 0;
        }
        for(int i=0;i<n;i++) {
            int ind = Math.abs(nums[i]) - 1;
            if(ind < 0 || ind >= nums.length) 
                continue;

            if(nums[ind] > 0) {
                nums[ind] *= -1;
            } else if(nums[ind] == 0) {
                nums[ind] = Integer.MIN_VALUE + 1; 
            }
        }
        for(int i=0;i<n;i++) {
            if(nums[i] >= 0) return i+1;
        }
        return n+1;
    }
}
