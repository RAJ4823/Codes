// Link: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-ways-to-stay-in-the-same-place-after-some-steps
 *  RUNTIME: 12 ms
 *  MEMORY: 6.5 MB
 *  DATE: 10-15-2023, 10:42:05 AM
 *
 */

// Solution:

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int n = min(steps / 2 + 1, arrLen);
        
        vector<int> curr(n, 0), prev(n, 0);
        prev[0] = 1;
        
        int mod = 1000000007; 
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j < n; j++) {
                curr[j] = prev[j] % mod;
                if (j > 0) {
                    curr[j] = (curr[j] + prev[j - 1]) % mod;
                }
                if (j < n - 1) {
                    curr[j] = (curr[j] + prev[j + 1]) % mod;
                }
            }
            prev = curr;
        }
        
        return curr[0];
    }
};
