// Link: https://leetcode.com/problems/soup-servings

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: soup-servings
 *  RUNTIME: 0 ms
 *  MEMORY: 6.6 MB
 *  DATE: 7-29-2023, 3:02:36 PM
 *
 */

// Solution:

class Solution {
public:
    double find(int a, int b, vector<vector<double>> & dp) {
        if (a <= 0) return (b <= 0) ? 0.5 : 1;
        if (b <= 0) return 0;
        if (dp[a][b] != -1) return dp[a][b];

        double ans = 0;
        for(int i=4; i>0; i--) {
            ans += 0.25 * find(a - i, b - 4 + i, dp);
        }
        return dp[a][b] = ans;
    }

    double soupServings(int n) {
        if(n >= 4800) return 1;
        n = (n+24)/25;
        vector<vector<double>> dp(n+1, vector<double> (n+1, -1));
        return find(n, n, dp);
    }
};
