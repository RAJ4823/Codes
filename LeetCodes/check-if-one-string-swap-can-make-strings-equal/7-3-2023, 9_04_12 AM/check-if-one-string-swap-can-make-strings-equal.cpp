// Link: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: check-if-one-string-swap-can-make-strings-equal
 *  RUNTIME: 0 ms
 *  MEMORY: 6 MB
 *  DATE: 7-3-2023, 9:04:12 AM
 *
 */

// Solution:

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        if(s1 == s2) return true;
        int p = -1;
        for(int i=0; i<s1.length(); i++) {
            if(s1[i] != s2[i]) {
                if(p == -1) {
                    p = i;
                } else {
                    swap(s1[i], s1[p]);
                    return s1 == s2;
                }
            }
        }
        return false;
    }
};
