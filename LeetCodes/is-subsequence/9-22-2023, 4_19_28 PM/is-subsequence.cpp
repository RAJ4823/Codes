// Link: https://leetcode.com/problems/is-subsequence

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: is-subsequence
 *  RUNTIME: 0 ms
 *  MEMORY: 6.6 MB
 *  DATE: 9-22-2023, 4:19:28 PM
 *
 */

// Solution:

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        while(i < s.size() && j < t.size()) {
            if(s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        if(i == s.size()) return true;
        return false;
    }
};
