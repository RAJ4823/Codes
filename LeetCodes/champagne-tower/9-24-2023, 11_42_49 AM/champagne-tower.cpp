// Link: https://leetcode.com/problems/champagne-tower

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: champagne-tower
 *  RUNTIME: 8 ms
 *  MEMORY: 14.5 MB
 *  DATE: 9-24-2023, 11:42:49 AM
 *
 */

// Solution:

class Solution {
public:
    double champagneTower(int x, int row, int col) {
        vector<double> curr(1, x);

        for(int i=0; i<=row; i++) {
            vector<double> next(i+2, 0.0);
            for(int j=0; j<=i; j++) {
                if(curr[j] > 1.0) {
                    next[j] += (curr[j] - 1) / 2;
                    next[j+1] += (curr[j] - 1) / 2;
                    curr[j] = 1.0;
                }
            }
            if(i < row) {
                curr = next;
            }
        }
        return curr[col];
    }
};
