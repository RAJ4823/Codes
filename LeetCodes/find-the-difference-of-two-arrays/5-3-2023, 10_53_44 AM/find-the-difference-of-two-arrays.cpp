// Link: https://leetcode.com/problems/find-the-difference-of-two-arrays

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-difference-of-two-arrays
 *  RUNTIME: 73 ms
 *  MEMORY: 33.4 MB
 *  DATE: 5-3-2023, 10:53:44 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v1, v2;
        set<int> s1(begin(nums1), end(nums1)), s2(begin(nums2), end(nums2));
        set_difference(begin(s1), end(s1), begin(s2), end(s2), back_inserter(v1));
        set_difference(begin(s2), end(s2), begin(s1), end(s1), back_inserter(v2));
        return {v1, v2};
    }
};
