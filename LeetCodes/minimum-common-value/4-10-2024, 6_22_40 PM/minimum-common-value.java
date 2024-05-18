// Link: https://leetcode.com/problems/minimum-common-value

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-common-value
 *  RUNTIME: 1 ms
 *  MEMORY: 62.3 MB
 *  DATE: 4-10-2024, 6:22:40 PM
 *
 */

// Solution:

class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int i = 0, j = 0;
        while(i < nums1.length && j < nums2.length) {
            if(nums1[i] < nums2[j]) 
                i++;
            else if(nums1[i] > nums2[j]) 
                j++;
            else
                return nums1[i];
        }
        return -1;
    }
}
