// Link: https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: make-string-a-subsequence-using-cyclic-increments
 *  RUNTIME: 34 ms
 *  MEMORY: 14.2 MB
 *  DATE: 8-24-2023, 10:18:07 PM
 *
 */

// Solution:

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            char curr = str1[i];
            char next = (curr == 'z') ? 'a' : (curr + 1);
            if (curr == str2[j] || next == str2[j]) {
                j++;
            } 
            i++;                
        }
        return (j == m);
    }
};
