// Link: https://leetcode.com/problems/find-the-difference

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-difference
 *  RUNTIME: 5 ms
 *  MEMORY: 7 MB
 *  DATE: 9-25-2023, 10:36:20 AM
 *
 */

// Solution:

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> ms;

        for(auto &ch: s) ms[ch]++;
        for(auto &ch: t) {
            ms[ch]--;
        }

        for(auto &x: ms) {
            if(x.second == -1) {
                return x.first;
            }
        }
        return s[0];
    }
};
