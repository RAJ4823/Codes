// Link: https://leetcode.com/problems/robot-return-to-origin

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: robot-return-to-origin
 *  RUNTIME: 14 ms
 *  MEMORY: 8 MB
 *  DATE: 6-4-2023, 10:30:06 AM
 *
 */

// Solution:

class Solution {
public:
    bool judgeCircle(string moves) {
        int countx = 0, county = 0;
        for(auto &ch: moves) {
            if(ch == 'R') countx++;
            if(ch == 'L') countx--;
            if(ch == 'U') county++;
            if(ch == 'D') county--;
        }
        return !(countx || county);
    }
};
