// Link: https://leetcode.com/problems/remove-palindromic-subsequences

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: remove-palindromic-subsequences
 *  RUNTIME: 3 ms
 *  MEMORY: 6.8 MB
 *  DATE: 9-16-2023, 3:14:06 PM
 *
 */

// Solution:

class Solution {
public:
    int removePalindromeSub(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i++] != s[j--])
                return 2;
        }
        return 1;
    }
};
