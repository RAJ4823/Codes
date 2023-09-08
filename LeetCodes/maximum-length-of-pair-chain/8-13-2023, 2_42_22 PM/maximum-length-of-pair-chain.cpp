// Link: https://leetcode.com/problems/maximum-length-of-pair-chain

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-length-of-pair-chain
 *  RUNTIME: 536 ms
 *  MEMORY: 159.2 MB
 *  DATE: 8-13-2023, 2:42:22 PM
 *
 */

// Solution:

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();

        pairs.push_back({INT_MAX, INT_MAX});
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        for(int i=0; i<n; i++) {
            for(int j=0; j<=n; j++) {
                if(pairs[i][1] < pairs[j][0]) {
                    dp[i][j] = (i == 0) ? 1 : max(1 + dp[i-1][i], dp[i-1][j]);
                } else {
                    dp[i][j] = (i == 0) ? 0 : dp[i-1][j];
                }
            }
        }
        return dp[n-1][n];
    }
};
