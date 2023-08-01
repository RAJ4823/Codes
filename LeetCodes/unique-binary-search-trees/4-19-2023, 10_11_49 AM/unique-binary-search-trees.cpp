// Link: https://leetcode.com/problems/unique-binary-search-trees

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: unique-binary-search-trees
 *  RUNTIME: 0 ms
 *  MEMORY: 6.2 MB
 *  DATE: 4-19-2023, 10:11:49 AM
 *
 */

// Solution:

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for(int i=2; i<=n; i++) {
            for(int j=1; j<=i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
