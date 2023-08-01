// Link: https://leetcode.com/problems/longest-uncommon-subsequence-i

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-uncommon-subsequence-i
 *  RUNTIME: 0 ms
 *  MEMORY: 6.2 MB
 *  DATE: 1-2-2023, 5:11:17 PM
 *
 */

// Solution:

class Solution {
public:
    int findLUSlength(string a, string b) {
        return (a == b) ? (-1) : (max(a.size(), b.size()));
    }
};
