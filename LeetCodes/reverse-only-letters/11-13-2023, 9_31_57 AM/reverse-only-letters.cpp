// Link: https://leetcode.com/problems/reverse-only-letters

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reverse-only-letters
 *  RUNTIME: 0 ms
 *  MEMORY: 6.6 MB
 *  DATE: 11-13-2023, 9:31:57 AM
 *
 */

// Solution:

class Solution {
public:
    bool isAlpha(char &ch) {
        if(ch >= 65 && ch <= 90) return true;
        if(ch >= 97 && ch <= 122) return true;
        return false;
    }
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(isAlpha(s[i]) && isAlpha(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            } else if(isAlpha(s[i])) {
                j--;
            } else if(isAlpha(s[j])) {
                i++;
            } else {
                i++;
                j--;
            }
        }
        return s;
    }
};
