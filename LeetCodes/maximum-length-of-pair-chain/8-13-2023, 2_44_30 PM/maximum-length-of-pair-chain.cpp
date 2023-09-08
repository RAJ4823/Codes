// Link: https://leetcode.com/problems/maximum-length-of-pair-chain

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-length-of-pair-chain
 *  RUNTIME: 429 ms
 *  MEMORY: 23.2 MB
 *  DATE: 8-13-2023, 2:44:30 PM
 *
 */

// Solution:

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        pairs.push_back({INT_MAX, INT_MAX});
        vector<int> dp(n+1, -1), prev(n+1, -1);

        for(int i=0; i<n; i++) {
            for(int j=0; j<=n; j++) {
                if(pairs[i][1] < pairs[j][0]) {
                    dp[j] = (i == 0) ? 1 : max(1 + prev[i], prev[j]);
                } else {
                    dp[j] = (i == 0) ? 0 : prev[j];
                }
            }
            prev = dp;
        }
        return dp[n];
    }
};
