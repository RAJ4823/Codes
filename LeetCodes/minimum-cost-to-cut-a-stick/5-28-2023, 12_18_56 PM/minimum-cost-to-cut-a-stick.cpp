// Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-cost-to-cut-a-stick
 *  RUNTIME: 110 ms
 *  MEMORY: 10.3 MB
 *  DATE: 5-28-2023, 12:18:56 PM
 *
 */

// Solution:

class Solution {
public:
    int find(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        if(j - i <= 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int res = 1e9, curr = (cuts[j] - cuts[i]);
        for(int index = i+1; index < j; index++) {
            res = min(res, curr + find(i, index, cuts, dp) + find(index, j, cuts, dp));
        }
        return dp[i][j] = res;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int size = cuts.size();
        vector<vector<int>> dp(size, vector<int> (size, -1));
        return find(0, size-1, cuts, dp);
    }
};
