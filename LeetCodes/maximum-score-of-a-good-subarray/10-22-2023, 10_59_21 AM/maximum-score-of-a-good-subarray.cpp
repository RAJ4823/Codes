// Link: https://leetcode.com/problems/maximum-score-of-a-good-subarray

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-score-of-a-good-subarray
 *  RUNTIME: 139 ms
 *  MEMORY: 89.8 MB
 *  DATE: 10-22-2023, 10:59:21 AM
 *
 */

// Solution:

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i = k, j = k;
        int ans = nums[k];
        int mini = nums[k];

        while (i > 0 || j < n - 1) {
            if (i == 0) {
                j++;
            } else if (j == n - 1) {
                i--;
            } else if (nums[i - 1] < nums[j + 1]) {
                j++;
            } else {
                i--;
            }

            mini = min(mini, min(nums[i], nums[j]));
            ans = max(ans, mini * (j - i + 1));
        }

        return ans;
    }
};
