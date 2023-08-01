// Link: https://leetcode.com/problems/domino-and-tromino-tiling

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: domino-and-tromino-tiling
 *  RUNTIME: 0 ms
 *  MEMORY: 6.5 MB
 *  DATE: 12-24-2022, 7:08:56 PM
 *
 */

// Solution:

const int mod = 1e9+7;

class Solution {
private:
    int find(int i, vector<int> &dp) {
        if(i == 0 || i == 1) return 1;
        if(i == 2) return 2;
        if(dp[i] != -1) return dp[i];
        
        int subAns = ((2*(find(i-1, dp) % mod) % mod) + (find(i-3, dp) % mod)) % mod;
        return dp[i] = subAns;
    }
public:
    int numTilings(int n) {
        vector<int> dp(n+1, -1);
        int ans = find(n, dp);
        return ans;
    }
};
