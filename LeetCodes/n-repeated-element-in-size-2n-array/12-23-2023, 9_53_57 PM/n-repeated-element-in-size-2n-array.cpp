// Link: https://leetcode.com/problems/n-repeated-element-in-size-2n-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: n-repeated-element-in-size-2n-array
 *  RUNTIME: 25 ms
 *  MEMORY: 25.2 MB
 *  DATE: 12-23-2023, 9:53:57 PM
 *
 */

// Solution:

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int half = nums.size() / 2, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (count(nums.begin(), nums.end(), nums[i]) > 1) {
                return nums[i];
            }
        }
        return 0;
    }
};
