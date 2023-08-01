// Link: https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-non-decreasing-subarray-from-two-arrays
 *  RUNTIME: 223 ms
 *  MEMORY: 162.3 MB
 *  DATE: 7-10-2023, 5:06:17 PM
 *
 */

// Solution:

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n, 0);
        int prev = 0, li = -1, res = 1, j = 0;

        for(int i=0; i<n; i++) {
            int mini = min(nums1[i], nums2[i]);
            int maxi = max(nums1[i], nums2[i]);

            if(mini >= prev) {
                ans[i] = mini;
            } 
            else if(maxi >= prev) {
                ans[i] = maxi;
                if(li == -1)
                    li = i;
            }
            else {
                ans[i] = mini;
            }
            
            if(maxi < prev) {
                if(li != -1) {
                    i = li - 1;
                    li = -1;
                } else {
                    i--;
                } 
                prev = 0;
                j = i+1;
            } else {
                prev = ans[i];
                res = max(res, i - j + 1);
            }
        }
        return res;
    }
};
