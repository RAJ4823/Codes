// Link: https://leetcode.com/problems/uncrossed-lines

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: uncrossed-lines
 *  RUNTIME: 10 ms
 *  MEMORY: 9.7 MB
 *  DATE: 5-11-2023, 10:52:59 AM
 *
 */

// Solution:

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> dp(m+1, 0), prev(m+1, 0);
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(nums1[i-1] == nums2[j-1]) {
                    dp[j] = 1 + prev[j-1];
                } else {
                    dp[j] = max(prev[j], dp[j-1]);
                }
            }
            prev = dp;
        }
        return dp[m];
    }
};
