// Link: https://leetcode.com/problems/count-all-possible-routes

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-all-possible-routes
 *  RUNTIME: 291 ms
 *  MEMORY: 12 MB
 *  DATE: 6-25-2023, 10:14:23 AM
 *
 */

// Solution:

class Solution {
public:
    int n, fin;
    int MAX_LEN = 101, MAX_FUEL = 201;
    int mod = 1e9 + 7;

    vector<vector<int>> dp;
    int dfs(int curr, vector<int> &locs, int fuel) {
        if(curr >= n || fuel < 0) return 0;
        if(dp[curr][fuel] != -1) return dp[curr][fuel];

        int count = (curr == fin);

        for(int next=0; next<n; next++) {
            if(next == curr) continue;
            int res = dfs(next, locs, fuel - abs(locs[curr] - locs[next]));
            count = (count % mod + res % mod) % mod;
        }
        return dp[curr][fuel] = count;
    }
    int countRoutes(vector<int>& locs, int start, int finish, int fuel) {
        n = locs.size();
        fin = finish;
        dp.resize(n, vector<int> (fuel+1, -1));
        int ans = dfs(start, locs, fuel);
        return ans;
    }
};
