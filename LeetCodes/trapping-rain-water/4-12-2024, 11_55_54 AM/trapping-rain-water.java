// Link: https://leetcode.com/problems/trapping-rain-water

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: trapping-rain-water
 *  RUNTIME: 1 ms
 *  MEMORY: 45.9 MB
 *  DATE: 4-12-2024, 11:55:54 AM
 *
 */

// Solution:

class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int[] left = new int[n];
        int[] right = new int[n];

        for(int i=0; i<n; i++) {
            left[i] = (i > 0) ? Math.max(left[i-1], height[i]) : height[i];
        }
        for(int i=n-1; i>=0; i--) {
            right[i] = (i < n - 1) ? Math.max(right[i+1], height[i]) : height[i];
        }

        int traped = 0;
        for(int i=1; i<n-1; i++) {
            traped += (Math.min(right[i], left[i]) - height[i]);
        }

        return traped;
    }
}
