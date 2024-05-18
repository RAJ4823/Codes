// Link: https://leetcode.com/problems/count-substrings-that-differ-by-one-character

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-substrings-that-differ-by-one-character
 *  RUNTIME: 13 ms
 *  MEMORY: 43.8 MB
 *  DATE: 5-9-2024, 11:54:08 AM
 *
 */

// Solution:

class Solution {
    public int countSubstrings(String s, String t) {
        int m = s.length(), n = t.length(), res = 0;
        int[][][] dp = new int[m+1][n+1][2];
        
        // dp[i][j] : count for s[0:i) & t[0:j)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i+1][j+1][0] = (s.charAt(i) == t.charAt(j)) ? dp[i][j][0] + 1 : 0;
                dp[i+1][j+1][1] = (s.charAt(i) == t.charAt(j)) ? dp[i][j][1] : dp[i][j][0] + 1;
                res += dp[i+1][j+1][1];
            }
        }
        
        return res;
    }
}
