// Link: https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-sum-of-mountain-triplets-ii
 *  RUNTIME: 4 ms
 *  MEMORY: 57.4 MB
 *  DATE: 4-12-2024, 12:17:59 PM
 *
 */

// Solution:

class Solution {
    public int minimumSum(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, Integer.MAX_VALUE);
        Arrays.fill(right, Integer.MAX_VALUE);

        for(int i=0; i<n; i++) {
            left[i] = (i > 0) ? Math.min(left[i - 1], nums[i]) : nums[i];
            right[n-i-1] = (n-i-1 < n-1) ? Math.min(right[n-i], nums[n-i-1]) : nums[n-i-1];
        }

        int sum = Integer.MAX_VALUE;
        for(int i=1; i<n-1; i++) {
            if(left[i-1] < nums[i] && nums[i] > right[i+1]) {
                sum = Math.min(sum, left[i-1] + nums[i] + right[i+1]);
            }
        }
        return sum == Integer.MAX_VALUE ? -1 : sum;
    }
}
