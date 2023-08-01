// Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-number-of-events-that-can-be-attended-ii
 *  RUNTIME: 778 ms
 *  MEMORY: 113.4 MB
 *  DATE: 7-15-2023, 11:50:48 AM
 *
 */

// Solution:

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(n+1, vector<int> (k+1, 0));
        sort(events.begin(), events.end());

        for(int i=n-1; i>=0; i--) {
            for(int j=1; j<=k; j++) {
                int next = upper_bound(events.begin()+i, events.end(), vector<int>{events[i][1]+1,0,0}) - events.begin();

                dp[i][j] = max(events[i][2] + dp[next][j-1], dp[i+1][j]);
            }
        }

        return dp[0][k];
    }
};
