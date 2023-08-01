// Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-subarray-of-1s-after-deleting-one-element
 *  RUNTIME: 48 ms
 *  MEMORY: 36.3 MB
 *  DATE: 7-5-2023, 8:42:55 AM
 *
 */

// Solution:

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int curr = 0, prev = -1, ans = INT_MIN;

        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                if(prev == -1) {
                    prev = curr;
                }
                else {
                    ans = max(ans, prev + curr);
                    prev = curr;
                }
                curr = 0;
            } else {
                curr++;
            }
        }
        ans = max(ans, prev + curr);
        if(ans == INT_MIN) return n-1;
        return ans;
    }
};
