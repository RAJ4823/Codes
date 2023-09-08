// Link: https://leetcode.com/problems/merge-sorted-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: merge-sorted-array
 *  RUNTIME: 5 ms
 *  MEMORY: 9.1 MB
 *  DATE: 8-2-2023, 10:20:13 AM
 *
 */

// Solution:

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> sorted;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                sorted.push_back(nums1[i++]);
            } else {
                sorted.push_back(nums2[j++]);
            }
        }
        while(i < m) {
            sorted.push_back(nums1[i++]);
        }
        while(j < n) {
            sorted.push_back(nums2[j++]);
        }
        nums1 = sorted;
    }
};
