// Link: https://leetcode.com/problems/climbing-stairs

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: climbing-stairs
 *  RUNTIME: 3 ms
 *  MEMORY: 6.2 MB
 *  DATE: 12-16-2022, 5:09:20 PM
 *
 */

// Solution:

class Solution {
private: 
    int find(int i,vector<int> &dp) {
        if(i < 0 ) return 0;
        if(i == 0) return 1;
        if(dp[i] != -1) return dp[i];

        return dp[i] = (find(i-1,dp) + find(i-2,dp));
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        // return find(n,dp);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
