// Link: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sum-of-absolute-differences-in-a-sorted-array
 *  RUNTIME: 89 ms
 *  MEMORY: 83.6 MB
 *  DATE: 11-25-2023, 11:14:16 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++) {
            ans[0] += abs(nums[0] - nums[i]);
        }
        for(int i=1; i<n; i++) {
            ans[i] = ans[i-1] + abs(nums[i] - nums[i-1]) * (2 * i - n);
        }
        return ans;
    }
};
