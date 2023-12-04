// Link: https://leetcode.com/problems/knight-dialer

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: knight-dialer
 *  RUNTIME: 115 ms
 *  MEMORY: 24 MB
 *  DATE: 11-27-2023, 11:52:11 AM
 *
 */

// Solution:

class Solution {
public:
    int mod = 1e9 + 7;
    int find(int curr, int steps, vector<vector<int>> &adj, vector<vector<int>> &dp) {
        if(steps == 0) return 1;
        if(dp[curr][steps] != -1) return dp[curr][steps];

        int count = 0;
        for(auto &next: adj[curr]) {
            count = (count + find(next, steps - 1, adj, dp)) % mod;
        }
        return dp[curr][steps] = count;
    }
    int knightDialer(int n) {
        if(n == 1) return 10;

        vector<vector<int>> dp(10, vector<int> (n+1, -1));
        vector<vector<int>> adj = {
            {4,6},
            {6,8},
            {7,9},
            {4,8},
            {0,3,9},
            {},
            {0,1,7},
            {2,6},
            {1,3},
            {2,4}
        };

        int count = 0;
        for(int i=0; i<10; i++) {
            count = (count + find(i, n-1, adj, dp)) % mod;
        }
        return count;
    }
};
