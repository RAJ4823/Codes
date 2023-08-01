// Link: https://leetcode.com/problems/stone-game-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: stone-game-ii
 *  RUNTIME: 15 ms
 *  MEMORY: 10.1 MB
 *  DATE: 5-26-2023, 12:07:15 PM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> dp;
    vector<int> sum;
    int find(int i, int m, vector<int> &arr) {
        if(i >= arr.size())         return 0;
        if(i + 2*m >= arr.size())   return sum[i];
        if(dp[i][m] != -1)          return dp[i][m];

        int maxi = 0;
        for(int k=1; k<=2*m; k++) {
            maxi = max(maxi, sum[i] - find(i + k, max(k, m), arr));
        }
        return dp[i][m] = maxi;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n, vector<int> (n, -1));
        sum.resize(n);
        sum[n-1] = piles[n-1];
        for(int i=n-2; i>=0; i--) {
            sum[i] = sum[i+1] + piles[i];
        }
        return find(0, 1, piles);
    }
};
