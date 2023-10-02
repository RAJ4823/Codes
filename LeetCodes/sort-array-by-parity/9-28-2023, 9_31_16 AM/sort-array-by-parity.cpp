// Link: https://leetcode.com/problems/sort-array-by-parity

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sort-array-by-parity
 *  RUNTIME: 10 ms
 *  MEMORY: 16.6 MB
 *  DATE: 9-28-2023, 9:31:16 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size() -1;
        vector<int> ans(nums.size());

        for(auto &val: nums) {
            ans[(val & 1) ? (j--) : (i++)] = val;
        }
        return ans;
    }
};
