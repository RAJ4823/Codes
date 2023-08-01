// Link: https://leetcode.com/problems/longest-palindromic-subsequence

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-palindromic-subsequence
 *  RUNTIME: 32 ms
 *  MEMORY: 6.4 MB
 *  DATE: 4-14-2023, 7:46:36 PM
 *
 */

// Solution:

class Solution {
public:
    int longestPalindromeSubseq(string s) {
      int n = s.size();
      int dp[n];
      memset(dp, 0, sizeof(dp));
      dp[n-1] = 1;
      for (int i = n-2, a = 0, b = 0; i >= 0; --i) {
        a = dp[i];
        dp[i] = 1;
        for (int j = i+1; j < n; ++j) {
          if (s[i] == s[j]) {
            b = dp[j];
            dp[j] = a+2;
            a = b;
          } else if (dp[j-1] > dp[j]){
            a = dp[j];
            dp[j] = dp[j-1];
          } else {
            a = dp[j];
          }
        }
      }
      return dp[n-1];
    }
};
