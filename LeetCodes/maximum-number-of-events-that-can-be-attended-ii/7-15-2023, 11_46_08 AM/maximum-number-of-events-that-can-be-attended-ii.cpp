// Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-number-of-events-that-can-be-attended-ii
 *  RUNTIME: 383 ms
 *  MEMORY: 112.7 MB
 *  DATE: 7-15-2023, 11:46:08 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int find(int i, int k, vector<vector<int>> &events) {
        if(i == n || k == 0) return 0;
        if(dp[i][k] != -1) return dp[i][k];

        int take=0, nottake=0;
        int j = upper_bound(events.begin()+i, events.end(), vector<int>{events[i][1]+1,0,0}) - events.begin();

        take = events[i][2] + find(j, k-1, events);
        nottake = find(i+1, k, events);
        return dp[i][k] = max(take, nottake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        n = events.size();

        dp.resize(n, vector<int> (k+1, -1));
        return find(0, k, events);
    }
};
