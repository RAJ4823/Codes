// Link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-operations-to-reduce-x-to-zero
 *  RUNTIME: 124 ms
 *  MEMORY: 99 MB
 *  DATE: 9-20-2023, 10:25:47 AM
 *
 */

// Solution:

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0, n = nums.size();
        for(auto &val: nums) total += val;
        int target = total - x;
        
        if(target < 0) return -1;
        if(target == 0) return n;

        int minOp = INT_MAX, curr = 0, l = 0, r = 0;

        while(r < n) {
            curr += nums[r++];

            while(curr > target && l < n) {
                curr -= nums[l++];
            }

            if(curr == target) {
                minOp = min(minOp, n - (r - l));
            }
        }
        
        if(minOp == INT_MAX) return -1;
        return minOp;
    }
};
