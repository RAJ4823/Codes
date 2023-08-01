// Link: https://leetcode.com/problems/longest-alternating-subarray

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-alternating-subarray
 *  RUNTIME: 27 ms
 *  MEMORY: 65.2 MB
 *  DATE: 7-12-2023, 4:33:38 PM
 *
 */

// Solution:

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int val = 1, ans = 0, len = 0;
        for(int i=0; i<n; i++) {
            val = 1;
            len = 1;
            for(int j=i+1; j<n; j++) {
                if(nums[j] - nums[i] == val) {
                    val = !val;
                    len++;
                } else {
                    break;
                }
            }
            if(len > 1) {
                ans = max(ans, len);
            }
        } 
        if(ans == 0) return -1;
        return ans;
    }
};
