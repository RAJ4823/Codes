// Link: https://leetcode.com/problems/merge-sorted-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: merge-sorted-array
 *  RUNTIME: 0 ms
 *  MEMORY: 8.9 MB
 *  DATE: 8-2-2023, 10:20:49 AM
 *
 */

// Solution:

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int j = 0, i = m; j<n; j++){
            nums1[i] = nums2[j];
            i++;
        }
        sort(nums1.begin(),nums1.end());
    }
};
