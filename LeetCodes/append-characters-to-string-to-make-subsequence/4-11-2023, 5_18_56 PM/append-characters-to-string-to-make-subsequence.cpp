// Link: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: append-characters-to-string-to-make-subsequence
 *  RUNTIME: 20 ms
 *  MEMORY: 10.8 MB
 *  DATE: 4-11-2023, 5:18:56 PM
 *
 */

// Solution:

class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size(), m = t.size();
        int rem = m, j = 0;
        for(int i=0;i<n; i++) {
            if(s[i] == t[j]) {
                j++;
                rem--;
            }
        }
        return rem;
    }
};
