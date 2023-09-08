// Link: https://leetcode.com/problems/longest-increasing-subsequence

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-increasing-subsequence
 *  RUNTIME: 9 ms
 *  MEMORY: 10.2 MB
 *  DATE: 8-13-2023, 2:34:41 PM
 *
 */

// Solution:

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 0;
        for(auto cur : nums) {
            if(len == 0 || nums[len-1] < cur) nums[len++] = cur;             // extend
            else *lower_bound(begin(nums), begin(nums) + len, cur) = cur;    // replace
        }
        return len;
    }
};
