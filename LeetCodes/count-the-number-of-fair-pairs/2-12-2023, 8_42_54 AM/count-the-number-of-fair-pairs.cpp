// Link: https://leetcode.com/problems/count-the-number-of-fair-pairs

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-the-number-of-fair-pairs
 *  RUNTIME: 286 ms
 *  MEMORY: 56.3 MB
 *  DATE: 2-12-2023, 8:42:54 AM
 *
 */

// Solution:

class Solution {
public:  
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long count = 0;
        
          for (int i = 1; i <= n; i++)
          {
            int left = lower_bound(nums.begin() + i, nums.end(), lower - nums[i-1]) - nums.begin();
            int right = upper_bound(nums.begin() + i, nums.end(), upper - nums[i-1]) - nums.begin() - 1;
            if (left <= right)  count += right - left + 1;
          }
        
        return count;
    }
};
