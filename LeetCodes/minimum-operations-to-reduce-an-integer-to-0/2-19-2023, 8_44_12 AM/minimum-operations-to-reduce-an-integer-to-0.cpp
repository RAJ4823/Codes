// Link: https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-operations-to-reduce-an-integer-to-0
 *  RUNTIME: 266 ms
 *  MEMORY: 14.3 MB
 *  DATE: 2-19-2023, 8:44:12 AM
 *
 */

// Solution:

class Solution {
public:
    int minOperations(int n) {
        int size = pow(2, log2(n) +1);
        vector<int> dp(size + 1, INT_MAX);
        int i = 1;
        while(i <= size) {
            dp[i] = 1;
            i*=2;
        }
        dp[0] = 0;
        if(dp[n] != INT_MAX) return dp[n];
        
        for(int i=0; i<=n; i++) {
            if(dp[i] != INT_MAX) continue;
            int j = 1;
            while(j <= size) {
                int diff = abs(i - j);
                if(dp[diff] != INT_MAX) {
                    dp[i] = min(dp[i], dp[diff] + dp[j]);
                }
                j*=2;
            }
            dp[i] = min(1 + dp[i-1], dp[i]);
        }
        
        return dp[n];
    }
};
