// Link: https://leetcode.com/problems/minimum-score-by-changing-two-elements

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-score-by-changing-two-elements
 *  RUNTIME: 100 ms
 *  MEMORY: 34.1 MB
 *  DATE: 4-1-2023, 9:35:36 AM
 *
 */

// Solution:

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int a1 = nums[n-1] - nums[2];
        int a2 = nums[n-3] - nums[0];
        int a3 = nums[n-2] - nums[1];
        int ans = min({a1, a2, a3});
        
        return ans;
    }
};
