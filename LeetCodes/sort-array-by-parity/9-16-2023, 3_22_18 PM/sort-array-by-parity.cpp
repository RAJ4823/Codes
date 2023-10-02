// Link: https://leetcode.com/problems/sort-array-by-parity

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sort-array-by-parity
 *  RUNTIME: 9 ms
 *  MEMORY: 16.6 MB
 *  DATE: 9-16-2023, 3:22:18 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n -1;
        vector<int> ans(n);

        for(auto &val: nums) {
            if(val % 2) {
                ans[j--] = val;
            } else {
                ans[i++] = val;
            }
        }
        return ans;
    }
};
