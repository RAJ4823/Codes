// Link: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-ways-to-form-a-target-string-given-a-dictionary
 *  RUNTIME: 271 ms
 *  MEMORY: 55.4 MB
 *  DATE: 4-16-2023, 9:36:21 AM
 *
 */

// Solution:

#define ll long long

class Solution {
public:
    ll mod = 1e9+7;

    int numWays(vector<string>& words, string target) {
        ll n = words.size(), sz = words[0].size(), m = target.size();

        if (sz < m) return 0;

        vector<vector<ll>> cnt(sz, vector<ll> (26, 0));
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < n; ++j) 
                cnt[i][words[j][i] - 'a']++;
        }
        
        vector<vector<int>> dp(sz + 1, vector<int>(m + 1));
        for (int i = 0; i < sz; ++i) {
            dp[i][0] = 1;
            for (int j = 0; j <= i && j < m; ++j) {
                dp[i + 1][j + 1] = ((cnt[i][target[j] - 'a'] * dp[i][j]) % mod + dp[i][j + 1]) % mod;
            }
        }
        return dp[sz][m];
    }
};
