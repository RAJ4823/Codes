// Link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-laser-beams-in-a-bank
 *  RUNTIME: 85 ms
 *  MEMORY: 23.5 MB
 *  DATE: 1-10-2024, 11:38:39 AM
 *
 */

// Solution:

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int lasersInPrevRow = 0, lasersInCurrRow = 0;
        int totalLasers = 0;

        for(auto &row: bank) {
            for(auto &cell: row) {
                if(cell == '1') {
                    totalLasers += lasersInPrevRow;
                    lasersInCurrRow++;
                }
            }
            if(lasersInCurrRow > 0) {
                lasersInPrevRow = lasersInCurrRow;
                lasersInCurrRow = 0;
            }
        }

        return totalLasers;
    }
};
