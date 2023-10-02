// Link: https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-operations-to-make-the-array-increasing
 *  RUNTIME: 8 ms
 *  MEMORY: 16.1 MB
 *  DATE: 9-13-2023, 7:20:51 PM
 *
 */

// Solution:

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] <= nums[i-1]) {
                count += abs(nums[i] - nums[i-1]) + 1;
                nums[i] = nums[i-1] + 1;
            }
        }
        return count;
    }
};
