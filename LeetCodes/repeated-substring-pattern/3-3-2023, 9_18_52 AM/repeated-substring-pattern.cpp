// Link: https://leetcode.com/problems/repeated-substring-pattern

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: repeated-substring-pattern
 *  RUNTIME: 15 ms
 *  MEMORY: 11.9 MB
 *  DATE: 3-3-2023, 9:18:52 AM
 *
 */

// Solution:

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str = (s + s);
        return str.find(s, 1) < s.size();
    }
};
