// Link: https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-cost-homecoming-of-a-robot-in-a-grid
 *  RUNTIME: 149 ms
 *  MEMORY: 149.8 MB
 *  DATE: 9-3-2023, 10:10:36 AM
 *
 */

// Solution:

class Solution {
public:
    int minCost(vector<int>& s, vector<int>& e, vector<int>& r, vector<int>& c) {
        int cost = 0;
        int startRow = s[0], startCol = s[1];
        int endRow = e[0], endCol = e[1];

        if(startRow < endRow) {
            while(startRow < endRow) {
                startRow += 1;
                cost += r[startRow];
            }
        } else if(startRow > endRow) {
            while(startRow > endRow) {
                startRow -= 1;
                cost += r[startRow];
            }
        }

        if(startCol < endCol) {
            while(startCol < endCol) {
                startCol += 1;
                cost += c[startCol];
            }
        } else if (startCol > endCol) {
            while(startCol > endCol) {
                startCol -= 1;
                cost += c[startCol];
            }
        }
        return cost;
    }
};
