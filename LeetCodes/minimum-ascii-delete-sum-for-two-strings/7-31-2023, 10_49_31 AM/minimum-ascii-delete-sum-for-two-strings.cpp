// Link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-ascii-delete-sum-for-two-strings
 *  RUNTIME: 36 ms
 *  MEMORY: 15.2 MB
 *  DATE: 7-31-2023, 10:49:31 AM
 *
 */

// Solution:

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i=n-1; i>=0; i--) {
            dp[i][m] = dp[i+1][m] + (int)(s1[i]);
        }
        for(int j=m-1; j>=0; j--) {
            dp[n][j] = dp[n][j+1] + (int)(s2[j]);
        }

        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                if(s1[i] == s2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = min(s1[i] + dp[i+1][j], s2[j] + dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
