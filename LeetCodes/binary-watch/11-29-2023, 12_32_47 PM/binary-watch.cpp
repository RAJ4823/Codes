// Link: https://leetcode.com/problems/binary-watch

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: binary-watch
 *  RUNTIME: 0 ms
 *  MEMORY: 6.7 MB
 *  DATE: 11-29-2023, 12:32:47 PM
 *
 */

// Solution:

class Solution {
public:
    string getTime(int h, int m) {
        return (to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int h = 0; h < 12; h++) {
            for(int m = 0; m < 60; m++) {
                if(__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    ans.push_back(getTime(h, m));
                }
            }
        }
        return ans;
    }
};
