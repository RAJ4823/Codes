// Link: https://leetcode.com/problems/array-partition

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: array-partition
 *  RUNTIME: 41 ms
 *  MEMORY: 28.6 MB
 *  DATE: 10-14-2023, 10:27:01 AM
 *
 */

// Solution:

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i=0; i<nums.size(); i+=2) {
            sum += nums[i];
        }
        return sum;
    }
};
