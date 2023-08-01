// Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-subarray-of-1s-after-deleting-one-element
 *  RUNTIME: 44 ms
 *  MEMORY: 39.5 MB
 *  DATE: 7-5-2023, 8:34:49 AM
 *
 */

// Solution:

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n, 0), left(n, 0);

        int ones = 0;
        for(int i=0; i<n; i++) {
            left[i] = ones;
            ones = (nums[i]) ? ones+1 : 0;
        }
        ones = 0;
        for(int i=n-1; i>=0; i--) {
            right[i] = ones; 
            ones = (nums[i]) ? ones+1 : 0;
        }

        int maxLen = INT_MIN;
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                maxLen = max(maxLen, left[i] + right[i]);
            }
        }
        if(maxLen == INT_MIN) return n-1;
        return maxLen;
    }
};
