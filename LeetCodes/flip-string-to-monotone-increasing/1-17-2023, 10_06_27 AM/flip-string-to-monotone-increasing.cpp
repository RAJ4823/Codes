// Link: https://leetcode.com/problems/flip-string-to-monotone-increasing

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: flip-string-to-monotone-increasing
 *  RUNTIME: 24 ms
 *  MEMORY: 10.9 MB
 *  DATE: 1-17-2023, 10:06:27 AM
 *
 */

// Solution:

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0, flips = 0;
        for(auto &ch: s) {
            if(ch == '1') ones++;
            else {
                flips++;
                flips = min(ones, flips);
            }
        }
        return flips;
    }
};
