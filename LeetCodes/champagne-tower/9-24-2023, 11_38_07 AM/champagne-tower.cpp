// Link: https://leetcode.com/problems/champagne-tower

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: champagne-tower
 *  RUNTIME: 20 ms
 *  MEMORY: 43.6 MB
 *  DATE: 9-24-2023, 11:38:07 AM
 *
 */

// Solution:

class Solution {
public:
    double champagneTower(int x, int row, int col) {
        vector<vector<double>> glass(101, vector<double> (101, 0.0));
        glass[0][0] = (double)x;
        for(int i=0; i<=row; i++) {
            for(int j=0; j<=i; j++) {
                if(glass[i][j] > 1.0) {
                    double extra = glass[i][j] - 1;
                    glass[i+1][j] += extra / 2;
                    glass[i+1][j+1] += extra / 2;
                    glass[i][j] = 1.0;
                }
            }
        }
        return glass[row][col];
    }
};
