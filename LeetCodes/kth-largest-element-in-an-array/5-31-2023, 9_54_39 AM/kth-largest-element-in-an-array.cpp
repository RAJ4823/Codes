// Link: https://leetcode.com/problems/kth-largest-element-in-an-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: kth-largest-element-in-an-array
 *  RUNTIME: 263 ms
 *  MEMORY: 76.1 MB
 *  DATE: 5-31-2023, 9:54:39 AM
 *
 */

// Solution:

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> st(nums.begin(), nums.end());
        auto it = st.end();
        for(int i=0; i <k; i++) it--;
        return *it;
    }
};
