// Link: https://leetcode.com/problems/count-ways-to-build-good-strings

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-ways-to-build-good-strings
 *  RUNTIME: 16 ms
 *  MEMORY: 9.4 MB
 *  DATE: 5-13-2023, 10:37:10 AM
 *
 */

// Solution:

#define ll long long
ll mod = 1000000007;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);
        for(int i=high; i>=0; i--) {
            int z = (i + zero > high) ? 0 : dp[i + zero];
            int o = (i + one > high) ? 0 : dp[i + one];
            int v = (i >= low && i <= high) ? 1 : 0;

            dp[i] = (v + z % mod + o % mod) % mod; 
        }
        return dp[0];
    }
};
