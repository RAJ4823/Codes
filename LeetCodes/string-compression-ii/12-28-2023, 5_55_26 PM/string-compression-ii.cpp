// Link: https://leetcode.com/problems/string-compression-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: string-compression-ii
 *  RUNTIME: 147 ms
 *  MEMORY: 49 MB
 *  DATE: 12-28-2023, 5:55:26 PM
 *
 */

// Solution:

class Solution {
public:
    int n, m = 101;
    int getLen(int freq) {
        if(freq == 1) return 1;
        if(freq < 10) return 2;
        if(freq <100) return 3;
        return 4;
    }
    int find(int i, int k, string &s, vector<vector<int>> &dp) {
        if(k < 0) return m;
        if(i == s.size() || s.size() - i <= k) return 0;
        if(dp[i][k] != m) return dp[i][k];

        int maxi = 0;
        vector<int> count(128);

        for(int j=i; j<s.size(); j++) {
            maxi = max(maxi, ++count[s[j]]);
            dp[i][k] = min(dp[i][k], getLen(maxi) + find(j+1, k - (j - i - maxi + 1), s, dp));
        }
        return dp[i][k];
    }
    int getLengthOfOptimalCompression(string s, int k) {
        n = s.size();
        vector<vector<int>> dp(n, vector<int> (k+1, m));
        return find(0, k, s, dp);
    }
};
