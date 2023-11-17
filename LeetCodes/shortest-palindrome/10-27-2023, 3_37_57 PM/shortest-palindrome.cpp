// Link: https://leetcode.com/problems/shortest-palindrome

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: shortest-palindrome
 *  RUNTIME: 0 ms
 *  MEMORY: 8.5 MB
 *  DATE: 10-27-2023, 3:37:57 PM
 *
 */

// Solution:

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        int i = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j]) i++;
        }
        if (i == n) return s;
        string right = s.substr(i);
        string left = s.substr(0, i);
        string revRight = right;
        reverse(revRight.begin(), revRight.end());
        return revRight + shortestPalindrome(left) + right;
    }

};
