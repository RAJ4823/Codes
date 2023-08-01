// Link: https://leetcode.com/problems/count-all-possible-routes

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-all-possible-routes
 *  RUNTIME: 594 ms
 *  MEMORY: 11.9 MB
 *  DATE: 6-25-2023, 10:35:03 AM
 *
 */

// Solution:

class Solution {
public:
    int mod = 1e9 + 7;

    int countRoutes(vector<int>& locs, int start, int finish, int fuel) {
        int n = locs.size();
        vector<vector<int>> dp(n, vector<int> (fuel+1, 0));

        for(int f=0; f<=fuel; f++) {
            for(int i=0; i<n; i++) {
                int count = (i == finish);
                for(int j=0; j<n; j++) {
                    int nf = f - abs(locs[i] - locs[j]);
                    if(i == j || nf < 0) continue;
                    count = (count % mod + dp[j][nf] % mod) % mod; 
                }
                dp[i][f] = count;
            }
        }
        return dp[start][fuel];
    }
};
