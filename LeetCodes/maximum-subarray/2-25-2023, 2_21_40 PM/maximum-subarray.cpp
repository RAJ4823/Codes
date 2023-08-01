// Link: https://leetcode.com/problems/maximum-subarray

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-subarray
 *  RUNTIME: 120 ms
 *  MEMORY: 67.7 MB
 *  DATE: 2-25-2023, 2:21:40 PM
 *
 */

// Solution:

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0, maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            curr += nums[i];
            maxi = max(maxi, curr);
            if(curr < 0) curr = 0;
        }
        return maxi;
    }
};
