// Link: https://leetcode.com/problems/number-of-music-playlists

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-music-playlists
 *  RUNTIME: 4 ms
 *  MEMORY: 8 MB
 *  DATE: 8-6-2023, 2:48:33 PM
 *
 */

// Solution:

#define ll long long

class Solution {
public:
    const int MOD = 1e9 + 7;
    ll solve(int n, int goal, int k, vector<vector<int>>& dp) {
        if (n == 0 && goal == 0) return 1;
        if (n == 0 || goal == 0) return 0;

        if (dp[n][goal] != -1) return dp[n][goal];

        ll pick = solve(n - 1, goal - 1, k, dp) * n;
        ll notpick = solve(n, goal - 1, k, dp) * max(n - k, 0);
        
        return dp[n][goal] = (pick + notpick) % MOD;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(goal + 1, -1));
        return solve(n, goal, k, dp);
    }
};
