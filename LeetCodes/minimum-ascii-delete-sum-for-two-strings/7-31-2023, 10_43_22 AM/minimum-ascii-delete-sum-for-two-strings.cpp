// Link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-ascii-delete-sum-for-two-strings
 *  RUNTIME: 52 ms
 *  MEMORY: 15.3 MB
 *  DATE: 7-31-2023, 10:43:22 AM
 *
 */

// Solution:

class Solution {
public:
    int n,m;
    vector<int> suff1, suff2;
    int find(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i == n) return suff2[j];
        if(j == m) return suff1[i];
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = find(i+1, j+1, s1, s2, dp);
        return dp[i][j] = min((int)(s1[i]) + find(i+1, j, s1, s2, dp), (int)(s2[j]) + find(i, j+1, s1, s2, dp));
    }
    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m = s2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        suff1.resize(n+1, 0);
        for(int i=n-1; i>=0; i--) {
            suff1[i] = suff1[i+1] + (int)(s1[i]);
        }
        suff2.resize(m+1, 0);
        for(int j=m-1; j>=0; j--) {
            suff2[j] = suff2[j+1] + (int)(s2[j]);
        }
        return find(0, 0, s1, s2, dp);
    }
};
