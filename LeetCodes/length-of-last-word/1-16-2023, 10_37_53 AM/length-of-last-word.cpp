// Link: https://leetcode.com/problems/length-of-last-word

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: length-of-last-word
 *  RUNTIME: 0 ms
 *  MEMORY: 6.6 MB
 *  DATE: 1-16-2023, 10:37:53 AM
 *
 */

// Solution:

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int count = 0;
        int i = n-1;
        while(i >= 0 && s[i] == ' ') i--;
        while(i >= 0 && s[i] != ' ') count++, i--;
        return count;
    }
};
