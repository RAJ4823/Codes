// Link: https://leetcode.com/problems/lexicographically-smallest-palindrome

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: lexicographically-smallest-palindrome
 *  RUNTIME: 43 ms
 *  MEMORY: 15 MB
 *  DATE: 5-22-2023, 9:05:09 PM
 *
 */

// Solution:

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        for(int i=0; i < n/2; i++) {
            if(s[i] != s[n-i-1]) {
                if(s[i] < s[n-i-1])
                    s[n-i-1] = s[i];
                else
                    s[i] = s[n-i-1];
            }
        }
        return s;
        
    }
};
