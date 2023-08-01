// Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-cost-to-cut-a-stick
 *  RUNTIME: 143 ms
 *  MEMORY: 10.1 MB
 *  DATE: 5-28-2023, 12:04:27 PM
 *
 */

// Solution:

class Solution {
public:
    int find(int i, int j, int start, int end, vector<int> &cuts, vector<vector<int>> &dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int min_cost = 1e9, curr_cost = (end - start);
        for(int index = i; index <= j; index++) {
            int left_cost = find(i, index-1, start, cuts[index], cuts, dp);
            int right_cost = find(index+1, j, cuts[index], end, cuts, dp);
            min_cost = min(min_cost, curr_cost + left_cost + right_cost);
        }
        return dp[i][j] = min_cost;
    }
    int minCost(int stick_len, vector<int>& cuts) {
        int cuts_len = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts_len, vector<int> (cuts_len, -1));
        return find(0, cuts_len-1, 0, stick_len, cuts, dp);
    }
};
