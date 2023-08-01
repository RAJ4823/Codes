// Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-subarray-of-1s-after-deleting-one-element
 *  RUNTIME: 39 ms
 *  MEMORY: 36.5 MB
 *  DATE: 7-5-2023, 8:47:43 AM
 *
 */

// Solution:

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), i = 0;
        int curr = 0, prev = -1, ans = INT_MIN;

        while(i < n) {
            while(i < n && nums[i]) {
                i++;
                curr++;
            }
            if(i == n) break;
            if(prev != -1) {
                ans = max(ans, prev + curr);
            }
            prev = curr;
            curr = 0;
            i++;
        }
        ans = max(ans, prev + curr);
        if(ans == INT_MIN) return n-1;
        return ans;
    }
};
