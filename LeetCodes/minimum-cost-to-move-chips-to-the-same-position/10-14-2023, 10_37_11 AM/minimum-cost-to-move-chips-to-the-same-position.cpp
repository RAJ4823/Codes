// Link: https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-cost-to-move-chips-to-the-same-position
 *  RUNTIME: 0 ms
 *  MEMORY: 7.8 MB
 *  DATE: 10-14-2023, 10:37:11 AM
 *
 */

// Solution:

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int parity[2] = {0};
        for(auto &x: position) {
            parity[x%2]++;
        }
        return min(parity[0], parity[1]);
    }
};
