// Link: https://leetcode.com/problems/pascals-triangle-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: pascals-triangle-ii
 *  RUNTIME: 0 ms
 *  MEMORY: 6.5 MB
 *  DATE: 8-2-2023, 3:42:13 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> dp(n+1, vector<int> (n+1 , 0));
        vector<int> ans;
        dp[0][0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=i; j++) {
                if(j == 0 || j == i) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
            }
        }
        return dp[n];
    }
};
