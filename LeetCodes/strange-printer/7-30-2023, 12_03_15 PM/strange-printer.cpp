// Link: https://leetcode.com/problems/strange-printer

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: strange-printer
 *  RUNTIME: 137 ms
 *  MEMORY: 9.6 MB
 *  DATE: 7-30-2023, 12:03:15 PM
 *
 */

// Solution:

class Solution {
public:
    int solve(int left, int right, string &s, vector<vector<int>> &dp) {
        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        
        int j = -1, ans = INT_MAX;
        for (int i = left; i < right; i++) {
            if (s[i] != s[right] && j == -1) {
                j = i;
            }
            if (j != -1) {
                ans = min(ans, 1 + solve(j, i, s, dp) + solve(i + 1, right, s, dp));
            }
        }
        
        if (j == -1)  ans = 0;
        return dp[left][right] = ans;
    };
    int strangePrinter(string s) {
        int n = s.size();
        vector dp(n, vector<int>(n, -1));
        return solve(0, n - 1, s, dp) + 1;
    }
};
