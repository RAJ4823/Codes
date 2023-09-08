// Link: https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-time-to-type-word-using-special-typewriter
 *  RUNTIME: 3 ms
 *  MEMORY: 6.1 MB
 *  DATE: 8-18-2023, 11:24:39 AM
 *
 */

// Solution:

class Solution {
public:
    int minTimeToType(string word) {
        int time = word.size();
        int point = 0;
        for(auto &ch: word) {
            int curr = (ch - 'a');
            int diff = abs(curr - point);
            time += min(diff, abs(26 - diff));
            point = curr;
        }
        return time;
    }
};
