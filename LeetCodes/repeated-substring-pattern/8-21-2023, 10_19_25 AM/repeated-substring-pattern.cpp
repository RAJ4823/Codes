// Link: https://leetcode.com/problems/repeated-substring-pattern

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: repeated-substring-pattern
 *  RUNTIME: 12 ms
 *  MEMORY: 11.8 MB
 *  DATE: 8-21-2023, 10:19:25 AM
 *
 */

// Solution:

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) < s.size();
    }
};
