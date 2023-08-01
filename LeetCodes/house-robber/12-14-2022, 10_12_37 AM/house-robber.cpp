// Link: https://leetcode.com/problems/house-robber

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: house-robber
 *  RUNTIME: 0 ms
 *  MEMORY: 7.6 MB
 *  DATE: 12-14-2022, 10:12:37 AM
 *
 */

// Solution:

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        int prev1 = nums[0];
        int prev2 = 0;
   
        for(int i=1; i<n; i++)
        {
            curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
