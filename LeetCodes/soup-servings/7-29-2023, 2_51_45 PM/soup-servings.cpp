// Link: https://leetcode.com/problems/soup-servings

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: soup-servings
 *  RUNTIME: 8 ms
 *  MEMORY: 138.4 MB
 *  DATE: 7-29-2023, 2:51:45 PM
 *
 */

// Solution:

class Solution {
public:
    int ops[4][2] = {{100,0}, {75, 25}, {50, 50}, {25, 75}};
    vector<vector<double>> dp;
    double find(int A, int B) {
        if(A <= 0) return (B <= 0) ? 0.5 : 1;
        if(B <= 0) return 0;
        if(dp[A][B] != -1.0) return dp[A][B];
        
        double prob = 0;
        for(int i=0; i<4; i++) {
            prob += 0.25 * find(A - ops[i][0], B - ops[i][1]);
        }
        return dp[A][B] = prob;
    }
    double soupServings(int n) {
        if(n >= 4800) return 1;
        dp.resize(n+1, vector<double> (n+1, -1));
        return find(n, n);
    }
};
