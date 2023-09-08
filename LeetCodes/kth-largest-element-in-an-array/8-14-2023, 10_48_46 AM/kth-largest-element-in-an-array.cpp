// Link: https://leetcode.com/problems/kth-largest-element-in-an-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: kth-largest-element-in-an-array
 *  RUNTIME: 225 ms
 *  MEMORY: 76.1 MB
 *  DATE: 8-14-2023, 10:48:46 AM
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
