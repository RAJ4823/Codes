// Link: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: make-two-arrays-equal-by-reversing-subarrays
 *  RUNTIME: 4 ms
 *  MEMORY: 43.9 MB
 *  DATE: 8-5-2024, 10:52:47 AM
 *
 */

// Solution:

class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        Arrays.sort(target);
        Arrays.sort(arr);
        return Arrays.equals(arr, target);
    }
}
