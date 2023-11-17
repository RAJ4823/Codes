// Link: https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-subsequence-in-non-increasing-order
 *  RUNTIME: 7 ms
 *  MEMORY: 10.9 MB
 *  DATE: 10-14-2023, 10:34:32 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int sum = 0, curr = 0;
        for(int i=0; i<nums.size(); i++) sum += nums[i];

        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            curr += nums[i];
            ans.push_back(nums[i]);
            if(sum - curr < curr)
                break;
        }
        return ans;
    }
};
