// Link: https://leetcode.com/problems/intersection-of-two-arrays

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: intersection-of-two-arrays
 *  RUNTIME: 8 ms
 *  MEMORY: 10.8 MB
 *  DATE: 9-14-2023, 11:35:49 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1, st2;
        for(auto &val: nums1) st1.insert(val);
        for(auto &val: nums2) {
            if(st1.find(val) != st1.end()) {
                st2.insert(val);
            }
        }
        return vector<int>(st2.begin(), st2.end());
    }
};
