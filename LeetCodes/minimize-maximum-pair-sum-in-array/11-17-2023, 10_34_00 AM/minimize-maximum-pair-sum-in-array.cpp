// Link: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimize-maximum-pair-sum-in-array
 *  RUNTIME: 194 ms
 *  MEMORY: 96.7 MB
 *  DATE: 11-17-2023, 10:34:00 AM
 *
 */

// Solution:

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int ans = 0;

        while(left < right) {
            ans = max(ans, nums[left++] + nums[right--]);
        }
        return ans;
    }
};
