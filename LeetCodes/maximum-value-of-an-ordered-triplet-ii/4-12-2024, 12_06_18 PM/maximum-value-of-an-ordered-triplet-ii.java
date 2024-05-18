// Link: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-value-of-an-ordered-triplet-ii
 *  RUNTIME: 4 ms
 *  MEMORY: 60.1 MB
 *  DATE: 4-12-2024, 12:06:18 PM
 *
 */

// Solution:

class Solution {
    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        long[] left = new long[n];
        long[] right = new long[n];

        for(int i=0; i<n; i++) {
            left[i] = (i > 0) ? Math.max(left[i - 1], (long)nums[i]) : (long)nums[i];
            right[n - i - 1] = (n - i - 1 < n - 1) ? Math.max(right[n - i], (long)nums[n - i - 1]) : (long)nums[n - i - 1];
        }

        long ans = 0;
        for(int i=1; i<n-1; i++) {
            ans = Math.max(ans, (left[i-1] - (long)nums[i]) * right[i+1]);
        }
        return ans;
    }
}
