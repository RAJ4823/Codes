// Link: https://leetcode.com/problems/count-all-possible-routes

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-all-possible-routes
 *  RUNTIME: 711 ms
 *  MEMORY: 11.9 MB
 *  DATE: 6-25-2023, 10:38:50 AM
 *
 */

// Solution:

class Solution {
public:

    int countRoutes(vector<int>& locs, int start, int finish, int fuel) {
        int n = locs.size();
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int> (fuel+1, 0));

        for(int f=0; f<=fuel; f++) {
            for(int i=0; i<n; i++) {
                dp[i][f] = (i == finish);
                for(int j=0; j<n; j++) {
                    if(i != j && f >= abs(locs[i] - locs[j])) {
                        dp[i][f] = (dp[i][f] % mod + dp[j][f - abs(locs[i] - locs[j])] % mod) % mod; 
                    }
                }
            }
        }
        return dp[start][fuel];
    }
};
