// Link: https://leetcode.com/problems/knight-probability-in-chessboard

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: knight-probability-in-chessboard
 *  RUNTIME: 3 ms
 *  MEMORY: 6.7 MB
 *  DATE: 7-22-2023, 10:49:13 AM
 *
 */

// Solution:

class Solution {
public:
    int dirs[8][2] = {{2,-1}, {2, 1}, {-2,-1}, {-2, 1}, {1, -2}, {1, 2}, {-1, -2}, {-1, 2}}; 
    double dp[30][30][105];

    double find(int row, int col, int n, int move) {
        if(row < 0 || row >= n || col < 0 || col >= n) return 0;
        if(move == 0) return 1;

        if(dp[row][col][move]) return dp[row][col][move];

        double prob = 0.0;
        for(int i=0; i<8; i++) {
            prob += find(row + dirs[i][0], col + dirs[i][1], n, move - 1) / 8.0;
        }
        return dp[row][col][move] = prob;
    }
    double knightProbability(int n, int k, int row, int col) {
        memset(dp, 0, sizeof(dp));
        return find(row, col, n, k);
    }
};
