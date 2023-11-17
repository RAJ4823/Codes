// Link: https://leetcode.com/problems/painting-the-walls

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: painting-the-walls
 *  RUNTIME: 166 ms
 *  MEMORY: 116.2 MB
 *  DATE: 10-14-2023, 9:57:42 AM
 *
 */

// Solution:

class Solution {
public:
    int find(int i, int j, vector<int>& cost, vector<int>& time, vector<vector<int>> &dp) {
        if(j <= 0) return 0;
        if(i >= cost.size()) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];

        int nottake = find(i+1, j, cost, time, dp);
        int take = cost[i] + find(i+1, j - time[i] - 1, cost, time, dp);
        return dp[i][j] = min(take, nottake);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return find(0, n, cost, time, dp);
    }
};
