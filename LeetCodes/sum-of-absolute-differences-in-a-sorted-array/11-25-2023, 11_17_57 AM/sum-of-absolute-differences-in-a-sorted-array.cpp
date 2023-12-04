// Link: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sum-of-absolute-differences-in-a-sorted-array
 *  RUNTIME: 90 ms
 *  MEMORY: 83.6 MB
 *  DATE: 11-25-2023, 11:17:57 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i=0; i<n; i++) {
            sum += abs(nums[0] - nums[i]);
        }
        int prev = nums[0];
        nums[0] = sum;
        for(int i=1; i<n; i++) {
            sum = nums[i-1] + abs(nums[i] - prev) * (2 * i - n);
            prev = nums[i];
            nums[i] = sum;
        }
        return nums;
    }
};
