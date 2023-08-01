// Link: https://leetcode.com/problems/count-ways-to-build-good-strings

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-ways-to-build-good-strings
 *  RUNTIME: 26 ms
 *  MEMORY: 17.1 MB
 *  DATE: 5-13-2023, 10:23:29 AM
 *
 */

// Solution:

#define ll long long
ll mod = 1000000007;

class Solution {
public:
    int l, h;
    int cz, co;

    int count(int len,vector<int> &dp) {
        if(len > h) return 0;
        if(dp[len] != -1) return dp[len];

        ll valid = 0;
        if(len >= l && len <= h) valid = 1;
        return dp[len] = (valid + count(len + cz, dp) % mod + count(len + co, dp) % mod) % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        l = low;
        h = high;
        cz = zero;
        co = one;
        vector<int> dp(h+1, -1);
        return count(0, dp);
    }
};
