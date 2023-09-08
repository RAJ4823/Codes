// Link: https://leetcode.com/problems/first-letter-to-appear-twice

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: first-letter-to-appear-twice
 *  RUNTIME: 2 ms
 *  MEMORY: 6 MB
 *  DATE: 8-18-2023, 11:18:07 AM
 *
 */

// Solution:

class Solution {
public:
    char repeatedCharacter(string s) {
        int alpha[26] = {0};
        for(auto &ch: s) if((alpha[ch - 'a']++) == 1) return ch;
        return 'r';
    }
};
