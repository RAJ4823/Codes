// Link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-ascii-delete-sum-for-two-strings
 *  RUNTIME: 53 ms
 *  MEMORY: 15.2 MB
 *  DATE: 7-31-2023, 10:38:59 AM
 *
 */

// Solution:

class Solution {
public:
    int n,m;
    int find(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i == n) {
            int sum = 0;
            for(int k=j; k<m; k++) {
                sum += (int)(s2[k]);
            }
            return sum;
        }
        if(j == m) {
            int sum = 0;
            for(int k=i; k<n; k++) {
                sum += (int)(s1[k]);
            }
            return sum;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) {
            return dp[i][j] = find(i+1, j+1, s1, s2, dp);
        } 
        int take1 = (int)(s1[i]) + find(i+1, j, s1, s2, dp);
        int take2 = (int)(s2[j]) + find(i, j+1, s1, s2, dp);
        return dp[i][j] = min(take1, take2);
    }
    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m = s2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return find(0, 0, s1, s2, dp);
    }
};
