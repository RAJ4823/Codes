// Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-cost-to-cut-a-stick
 *  RUNTIME: 61 ms
 *  MEMORY: 10.3 MB
 *  DATE: 5-28-2023, 12:25:14 PM
 *
 */

// Solution:

class Solution {
public:

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int size = cuts.size();
        vector<vector<int>> dp(size, vector<int> (size, 0));

        for(int i=size-1; i>=0; i--) {
            for(int j=i+2; j<size; j++) {
                int res = 1e9;
                for(int k=i+1; k<j; k++) {
                    res = min(res, cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = res;
            }   
        }
        return dp[0][size-1];
    }
};
